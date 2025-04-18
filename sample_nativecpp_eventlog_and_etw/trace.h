#pragma once
#include <windows.h>
#include <evntprov.h>
#include <TraceLoggingProvider.h>
#include <winmeta.h>


//�C�x���g���O�EETW�̏o�͕��@�T���v���B�A�v�����ŋ��ʂƂ���l�͌Œ�Ƃ��A���b�Z�[�W�o�͂��ƂɈقȂ�l���p�����[�^�Ƃ���A�Ƃ������j�ō쐬�����B

/// <summary>
/// �C�x���g���O�̓o�^���s���B����𐬌�������܂ł́AEventLogWrite�Ȃǂ̑����\�b�h�͏������s��Ȃ��B
/// </summary>
/// <returns></returns>
DWORD EventLogInitialize();

/// <summary>
/// �C�x���g���O�̉������s���B
/// </summary>
/// <returns></returns>
DWORD EventLogFinalize();

/// <summary>
/// �C�x���g���O�̏������݂��s���B
/// �\�[�X�E�J�e�S���͌Œ�́i���ʂ́j�l�Ƃ���B
/// </summary>
/// <param name="level">���O���x���BWINEVENT_LEVEL_CRITICAL�`WINEVENT_LEVEL_VERBOSE�̒l���w�肷�邱�ƁB
/// �C�x���g��ނ̐U�蕪���ɂ��g�p���ACRITICAL�EERROR�̓G���[�AWARNING�͌x���A�����艺�͏��Ƃ���B</param>
/// <param name="eventId">�C�x���g���O�ɏo�͂��郁�b�Z�[�W�BEventLogMessage.h�ɒ�`���ꂽ���b�Z�[�W�i�C�x���g�jID���w�肷��B</param>
DWORD EventLogWrite(int level, ULONG eventId);





