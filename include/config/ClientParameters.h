#pragma once
#include <ArduinoJson.h>

class ClientParameters {
    public:
    // use the numeric IP instead of the name for the server:
    // IP Address server(74,125,232,128);  // numeric IP for Google (no DNS)
    const PROGMEM IPAddress apiServer = 1234567890;    // name address for Google (using DNS)
    const PROGMEM uint16_t clientPort = 80;
    
    const PROGMEM int waitTimePerConnectionAttempt = 5000; // 5 segundos
    
    const PROGMEM  char* msgTrace = "Hello server";
    bool readingLines = true;
    unsigned long timoutReference; // defined at runtime
    const PROGMEM unsigned long responseTimeoutLimit = 3000;
    bool serverIsUp = false;
    char server_response_chars;
    char *server_response;
    char *server_response_line;

    // sizes
    const PROGMEM size_t signatureRequestSize = 200;

    // post_signature_request
    StaticJsonDocument<200> signatureRequest_Json;
    char signatureRequest_Char[200];
    
    // get_cyclobot_session_token
    StaticJsonDocument<200> loginParameters_Json;
    char loginParameters_Char[200];
    char sessionToken;
    char *serverRawResponse;
    char *jsonStart;
    char *jsonPart;

    StaticJsonDocument<512> responseJson;
    DeserializationError deserializationError;
};