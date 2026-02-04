#pragma once
#include <LinkedList.h>
#include <RTCLib.h>

class LogData {
    public:
        LogData();
        struct Log_Message {
            DateTime date_and_time;
            char *class_and_method;            // [class::method]
            char *message;
            bool user_can_see;                 // default = false
            bool send_now;                     // used by stream_logs();
        };

        // Create linked-lists struct
        // Every list must end with an 's'
        // LinkedList<Log_Message> log_messages;
        
        // Linked-lists INSERTITION methods
        void add(DateTime date_and_time,
                    char *class_and_method,
                    char *log_message,
                    bool user_can_see,
                    bool send_now
                );
};