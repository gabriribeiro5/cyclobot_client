#pragma once
#include <ArduinoJson.h>
#include <avr/pgmspace.h>
#include "IPAddress.h"

class ClientParameters {
    public:
    ClientParameters();
    // use the numeric IP instead of the name for the server:
    // IP Address server(74,125,232,128);                     // numeric IP for Google (no DNS)
    const PROGMEM IPAddress apiServer = 1234567890;           // name address for Google (using DNS)
    const PROGMEM uint16_t clientPort = 80;
    
    const PROGMEM int waitTimePerConnectionAttemptInMillis = 5000;    // 5 seconds
    const PROGMEM int dataStreamLengthInSeconds = 120;    // 2 minutes
    
    const PROGMEM  char* msgTrace = "Hello server";
    bool readingLines = true;
    unsigned long timoutReference;                            // defined at runtime
    const PROGMEM unsigned long responseTimeoutLimit = 3000;
    bool serverIsUp = false;
    char server_response_chars;
    char *server_response;
    char *server_response_line;

    // sizes
    static const size_t SIGNATURE_REQUESTS_CAPACITY = 80;
    static const size_t LOGIN_PARAMETERS_CAPACITY = 80;
    static const size_t RESPONSE_JSON_CAPACITY = 80;

    // post_signature_request
    StaticJsonDocument<SIGNATURE_REQUESTS_CAPACITY> signatureRequest_Json;
    char signatureRequest_Char[SIGNATURE_REQUESTS_CAPACITY];
    
    // get_cyclobot_session_token
    StaticJsonDocument<LOGIN_PARAMETERS_CAPACITY> loginParameters_Json;
    char loginParameters_Char[LOGIN_PARAMETERS_CAPACITY];
    const char *sessionToken;
    char *serverRawResponse;
    char *jsonStart;
    char *jsonPart;

    StaticJsonDocument<RESPONSE_JSON_CAPACITY> responseJson;
    DeserializationError deserializationError;
};