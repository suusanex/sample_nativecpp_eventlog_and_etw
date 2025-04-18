#pragma once
#include <windows.h>
#include <evntprov.h>
#include <TraceLoggingProvider.h>
#include <winmeta.h>


//イベントログ・ETWの出力方法サンプル。アプリ内で共通とする値は固定とし、メッセージ出力ごとに異なる値をパラメータとする、という方針で作成した。

/// <summary>
/// イベントログの登録を行う。これを成功させるまでは、EventLogWriteなどの他メソッドは処理を行わない。
/// </summary>
/// <returns></returns>
DWORD EventLogInitialize();

/// <summary>
/// イベントログの解除を行う。
/// </summary>
/// <returns></returns>
DWORD EventLogFinalize();

/// <summary>
/// イベントログの書き込みを行う。
/// ソース・カテゴリは固定の（共通の）値とする。
/// </summary>
/// <param name="level">ログレベル。WINEVENT_LEVEL_CRITICAL～WINEVENT_LEVEL_VERBOSEの値を指定すること。
/// イベント種類の振り分けにも使用し、CRITICAL・ERRORはエラー、WARNINGは警告、それより下は情報とする。</param>
/// <param name="eventId">イベントログに出力するメッセージ。EventLogMessage.hに定義されたメッセージ（イベント）IDを指定する。</param>
DWORD EventLogWrite(int level, ULONG eventId);





