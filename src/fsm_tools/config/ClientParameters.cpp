#include "../../../include/fsm_tools/config/ClientParameters.h"

ClientParameters::ClientParameters()
: apiServer(1234567890),
  clientPort(80),

  waitTimePerConnectionAttemptInMillis(5000),
  dataStreamLengthInSeconds(120),

  msgTrace("Hello server"),
  readingLines(true),
  timoutReference(0),
  responseTimeoutLimit(3000),
  serverIsUp(false),
  server_response_chars(0),
  server_response(nullptr),
  server_response_line(nullptr),

  signatureRequest_Json(),
  signatureRequest_Char(),

  loginParameters_Json(),
  loginParameters_Char(),
  sessionToken(0),
  serverRawResponse(nullptr),
  jsonStart(nullptr),
  jsonPart(nullptr),

  responseJson(),
  deserializationError()
{
    // The upward initialization handles constants and non-constants.
    // No need to assign variables again in the body!
}