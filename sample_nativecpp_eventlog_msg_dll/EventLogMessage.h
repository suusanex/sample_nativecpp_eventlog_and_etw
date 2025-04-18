//
//  Values are 32 bit values laid out as follows:
//
//   3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1 1 1
//   1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0
//  +---+-+-+-----------------------+-------------------------------+
//  |Sev|C|R|     Facility          |               Code            |
//  +---+-+-+-----------------------+-------------------------------+
//
//  where
//
//      Sev - is the severity code
//
//          00 - Success
//          01 - Informational
//          10 - Warning
//          11 - Error
//
//      C - is the Customer code flag
//
//      R - is a reserved bit
//
//      Facility - is the facility code
//
//      Code - is the facility's status code
//
//
// Define the facility codes
//


//
// Define the severity codes
//


//
// MessageId: EVENTLOG_MSG_OTHER_ERROR
//
// MessageText:
//
// その他のエラーが発生しました。
//
#define EVENTLOG_MSG_OTHER_ERROR         0xC0000001L

//
// MessageId: EVENTLOG_MSG_OTHER_WARNING
//
// MessageText:
//
// その他の警告が発生しました。
//
#define EVENTLOG_MSG_OTHER_WARNING       0x80000002L

//
// MessageId: EVENTLOG_MSG_OTHER_INFORMATION
//
// MessageText:
//
// その他の情報が発生しました。
//
#define EVENTLOG_MSG_OTHER_INFORMATION   0x40000003L

