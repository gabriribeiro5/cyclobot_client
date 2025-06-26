#pragma once

class ClientParameters {
    public:
        // use the numeric IP instead of the name for the server:
        // IP Address server(74,125,232,128);  // numeric IP for Google (no DNS)
        char apiServer = "www.google.com";    // name address for Google (using DNS)
        int clientPort = 80;
        
        int waitTimePerConnectionAttempt = 5000; // 5 segundos
        
        char msgTrace = "Hello server";
        bool readingLines = true;
        unsigned long timoutReference; // defined at runtime
        unsigned long responseTimeoutLimit = 3000;
        bool serverIsUp = false;

        // post_signature_request
        StaticJsonDocument<200> signatureRequest_Json;
        String signatureRequest_String;
        
        
        // get_cyclobot_session_token
        StaticJsonDocument<200> loginParameters_Json;
        String loginParameters_String;
        String sessionToken;
        String serverRawResponse;
        int jsonStart;
        String jsonPart;

        StaticJsonDocument<512> responseJson;
        DeserializationError deserializationError;
}