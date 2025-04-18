#include "trace.h"
#include <atlstr.h>

TRACELOGGING_DEFINE_PROVIDER(
    g_hTraceProvider,
    "sample_nativecpp_eventlog_and_etw_TraceProvider",
    // 27997477-8292-5db5-0aa8-85b7da832b17
    (0x27997477, 0x8292, 0x5db5, 0x0a, 0xa8, 0x85, 0xb7, 0xda, 0x83, 0x2b, 0x17));

LPCWSTR g_TraceSource = L"sample_nativecpp_eventlog_and_etw";
HANDLE g_hEventLog = nullptr;


DWORD EventLogInitialize()
{
	if (g_hEventLog) return ERROR_SUCCESS;

	g_hEventLog = RegisterEventSourceW(nullptr, g_TraceSource);
	if (!g_hEventLog)
	{
		const DWORD win32Err = GetLastError();
		{
			CStringW msg;
			msg.Format(L"RegisterEventSourceW failed. Win32Err=0x%X", win32Err);
			OutputDebugStringW(msg);
		}
		return win32Err;
	}

	return ERROR_SUCCESS;
}

DWORD EventLogFinalize()
{
	if (!g_hEventLog) return ERROR_SUCCESS;

	if (!DeregisterEventSource(g_hEventLog))
	{
		const DWORD win32Err = GetLastError();
		{
			CStringW msg;
			msg.Format(L"DeregisterEventSource failed. Win32Err=0x%X", win32Err);
			OutputDebugStringW(msg);
		}
		return win32Err;
	}
	g_hEventLog = nullptr;
	return ERROR_SUCCESS;
}

DWORD EventLogWrite(int level, ULONG eventId)
{
	if (!g_hEventLog) return ERROR_INVALID_HANDLE;

	WORD eventType;
	switch (level)
	{
	case WINEVENT_LEVEL_CRITICAL:
	case WINEVENT_LEVEL_ERROR:
		eventType = EVENTLOG_ERROR_TYPE;
		break;
	case WINEVENT_LEVEL_WARNING:
		eventType = EVENTLOG_WARNING_TYPE;
		break;
	case WINEVENT_LEVEL_INFO:
	case WINEVENT_LEVEL_VERBOSE:
	default:
		eventType = EVENTLOG_INFORMATION_TYPE;
		break;
	}

	if (!ReportEventW(
		g_hEventLog,
		eventType,
		0,
		eventId,
		nullptr,
		0,
		0,
		nullptr,
		nullptr
	))
	{
		const DWORD win32Err = GetLastError();
		{
			CStringW msg;
			msg.Format(L"ReportEventW failed. Win32Err=0x%X, level=%d, eventId=%u", win32Err, level, eventId);
			OutputDebugStringW(msg);
		}
		return win32Err;
	}

	return ERROR_SUCCESS;

}

