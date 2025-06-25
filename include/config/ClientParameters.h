#pragma once

class ClientParameters {
    public:
        // use the numeric IP instead of the name for the server:
        //IPAddress server(74,125,232,128);  // numeric IP for Google (no DNS)
        char apiServer[] = "www.google.com";    // name address for Google (using DNS)
        int clientPort = 80;
        
        int waitTimePerConnectionAttempt = 5000; // 5 segundos
        int wifiMaxAttempt = 3;
        
        char msgTrace = "Hello server";
        bool readingLines = true;
        unsigned long response_timeout_limit = millis();
        bool serverIsUp = false;

        StaticJsonDocument<200> signatureRequest_Json;
        String signatureRequest_String;
        
        StaticJsonDocument<200> loginParameters_Json;
        String loginParameters_String;

        String session_token;
}