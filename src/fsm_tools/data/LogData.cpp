#include "../../../include/fsm_tools/data/LogData.h"
#include <LinkedList.h>
#include <RTCLib.h>
LogData::LogData()
{
    log_messages = LinkedList<Log_Message>();
};

/************************ INSERT METHODS ************************/
void LogData::add(DateTime date_and_time,
                    char *class_and_method,
                    char *log_message,
                    bool user_can_see,
                    bool send_now
                )
{
    Log_Message new_msg = {
        date_and_time,
        class_and_method,
        log_message,
        user_can_see,
        send_now
    };
    log_messages.add(new_msg);
};
