# WindowsイベントログをネイティブC++で出力するサンプル

WindowsイベントログをネイティブC++で出力するサンプルです。

Win32APIで直接イベントログを出力しています。（ETWでの出力も追加予定です）

## インストール

### Win32APIの場合

ビルドしたモジュールを任意の場所に配置した後、sample_nativecpp_eventlog_msg_dll.dllのパスをレジストリに登録します。

EventLogAPITypeRegister.regが登録内容を示しています。

ただしパスは次のパスになっています。配置場所に合わせて変更する必要があります。

`%Temp%\sample_nativecpp_eventlog_msg_dll\sample_nativecpp_eventlog_msg_dll.dll`

## 解説

sample_nativecpp_eventlog_msg_dll.dllが、イベントログのメッセージ定義を持つDLLです。定義のみの実装で、処理は何も入っていません。

EventLogMessage.mcファイルへ、仕様に従ってメッセージを定義します。

[公式ドキュメント メッセージ テキスト ファイル](https://learn.microsoft.com/ja-jp/windows/win32/eventlog/message-text-files)

リビルドすると、それをもとにした同名の.h,.rcファイルが自動生成されます。

イベントログを出力する側のモジュールは、イベントIDの数値だけを指定することで出力できます。ネイティブC++プロジェクトからは、生成された.hファイルの定義を使うことができます。


