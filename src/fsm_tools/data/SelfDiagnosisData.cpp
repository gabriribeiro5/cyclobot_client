#include "../../../include/fsm_tools/data/SelfDiagnosisData.h"
#include <LinkedList.h>
#include <RTCLib.h>
SelfDiagnosisData::SelfDiagnosisData()
{   
    // Initialize static storage for serialized JSON
    // The actual DynamicJsonDocument is allocated on-demand in ClientComm
};

/************************ SEARCH METHODS ************************/
SelfDiagnosisData::SelfDiag_Bool SelfDiagnosisData::selfdiag_bool(char *name)
{
    // for (int i = 0; i < selfdiag_bool_list.size(); i++)
    // {
    //     SelfDiag_Bool item = selfdiag_bool_list.get(i);

    //     if (strcmp(item.name, name) == 0)   // compare string contents
    //     {
    //         return item;
    //     }
    // }

    // Return a "null" object if not found
    SelfDiag_Bool empty = { nullptr, false, nullptr, false, 0, false, false, DateTime() };
    return empty;
}

// SelfDiagnosisData::SelfDiag_Int SelfDiagnosisData::selfdiag_int(char *name)
// {
//     for (int i = 0; i < selfdiag_int_list.size(); i++)
//     {
//         SelfDiag_Int item = selfdiag_int_list.get(i);
//         if (strcmp(item.name, name) == 0)   // compare string contents
//         {
//             return item;
//         }
//     }
//     // Return a "null" object if not found
//     SelfDiag_Int empty = { nullptr, false, nullptr, false, 0, false, false, DateTime() };
//     return empty;
// };
// SelfDiagnosisData::SelfDiag_Char SelfDiagnosisData::selfdiag_char(char *name)
// {
//     for (int i = 0; i < selfdiag_char_list.size(); i++)
//     {
//         SelfDiag_Char item = selfdiag_char_list.get(i);
//         if (strcmp(item.name, name) == 0)   // compare string contents
//         {
//             return item;
//         }
//     }
//     // Return a "null" object if not found
//     SelfDiag_Char empty = { nullptr, false, nullptr, false, 0, false, false, DateTime() };
//     return empty;
// };

/************************ INSERT METHODS ************************/
void SelfDiagnosisData::add_parameter(char* type,
                                char *name,
                                bool value,
                                char *description,
                                bool user_can_see,
                                bool updated_by,
                                DateTime last_update
                            )
{
    if (strcmp(type, "bool") == 0) {
        SelfDiag_Bool new_bool = {
            name,
            value,
            description,                        // data description (for final user - not admin or server)
            user_can_see,                       // default = true
            updated_by,                         // default = 0 (server communication); 1 = (user communication)
            false,                              // default = false
            true,                               // default = true
            last_update
        };
        // selfdiag_bool_list.add(new_bool);
    };
    if (strcmp(type, "int") == 0) {
        SelfDiag_Int new_int = {
            name,
            value,
            description,                        // data description (for final user - not admin or server)
            user_can_see,                       // default = true
            updated_by,                         // default = 0 (server communication); 1 = (user communication)
            false,                              // default = false
            true,                               // default = true
            last_update
        };
        // selfdiag_int_list.add(new_int);
    };
    if (strcmp(type, "char") == 0) {
        SelfDiag_Char new_char = {
            name,
            value,
            description,                        // data description (for final user - not admin or server)
            user_can_see,                       // default = true
            updated_by,                         // default = 0 (server communication); 1 = (user communication)
            false,                              // default = false
            true,                               // default = true
            last_update
        };
        // selfdiag_char_list.add(new_char);
    };
};
