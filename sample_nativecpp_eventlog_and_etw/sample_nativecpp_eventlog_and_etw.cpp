// sample_nativecpp_eventlog_and_etw.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
#include "Trace.h"
#include "../sample_nativecpp_eventlog_msg_dll/EventLogMessage.h"

int main()
{
    std::cout << "Hello World!\n";

    {
        const auto ret = EventLogInitialize();
        if (ret != ERROR_SUCCESS) {
            std::cout << "EventLogInitialize failed. ret=0x" << std::hex << ret << "\n";
            return 1;
        }
    }
	{
		const auto ret = EventLogWrite(WINEVENT_LEVEL_ERROR, EVENTLOG_MSG_OTHER_ERROR);
		if (ret != ERROR_SUCCESS) {
			std::cout << "EventLogWrite failed. ret=0x" << std::hex << ret << "\n";
			return 1;
		}
	}
	{
		const auto ret = EventLogWrite(WINEVENT_LEVEL_WARNING, EVENTLOG_MSG_OTHER_WARNING);
		if (ret != ERROR_SUCCESS) {
			std::cout << "EventLogWrite failed. ret=0x" << std::hex << ret << "\n";
			return 1;
		}
	}
	{
		const auto ret = EventLogWrite(WINEVENT_LEVEL_INFO, EVENTLOG_MSG_OTHER_INFORMATION);
		if (ret != ERROR_SUCCESS) {
			std::cout << "EventLogWrite failed. ret=0x" << std::hex << ret << "\n";
			return 1;
		}
	}
	{
		const auto ret = EventLogFinalize();
		if (ret != ERROR_SUCCESS) {
			std::cout << "EventLogFinalize failed. ret=0x" << std::hex << ret << "\n";
			return 1;
		}
	}

	return 0;
}

// プログラムの実行: Ctrl + F5 または [デバッグ] > [デバッグなしで開始] メニュー
// プログラムのデバッグ: F5 または [デバッグ] > [デバッグの開始] メニュー

// 作業を開始するためのヒント: 
//    1. ソリューション エクスプローラー ウィンドウを使用してファイルを追加/管理します 
//   2. チーム エクスプローラー ウィンドウを使用してソース管理に接続します
//   3. 出力ウィンドウを使用して、ビルド出力とその他のメッセージを表示します
//   4. エラー一覧ウィンドウを使用してエラーを表示します
//   5. [プロジェクト] > [新しい項目の追加] と移動して新しいコード ファイルを作成するか、[プロジェクト] > [既存の項目の追加] と移動して既存のコード ファイルをプロジェクトに追加します
//   6. 後ほどこのプロジェクトを再び開く場合、[ファイル] > [開く] > [プロジェクト] と移動して .sln ファイルを選択します
