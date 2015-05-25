#include "Logger.h"
#include <stdexcept>

//using std::endl;
//using std::string;
//using std::vector;
//using std::ofstream;
//using std::runtime_error;
using namespace std;

const string Logger::kLogLevelDebug = "DEBUG";
const string Logger::kLogLevelInfo = "INFO";
const string Logger::kLogLevelError = "ERROR";

const char* const Logger::kLogFileName = "log.out";
bool Logger::sInitialized = false;
ofstream Logger::sOutputStream;

void Logger::log(const string& inMessage, const string& inLogLevel)
{
  if (!sInitialized) init();
  sOutputStream << inLogLevel << ": " << inMessage << endl;
}

void Logger::log(const vector<string>& inMessages, const string& inLogLevel)
{
  for (size_t i = 0; i < inMessages.size(); i++) {
    log(inMessages[i], inLogLevel);
  }
}

void Logger::teardown()
{
  if (sInitialized) {
    sOutputStream.close();
    sInitialized = false;
  }
}

void Logger::init()
{
  if (!sInitialized) sOutputStream.open(kLogFileName, ios_base::app);
  if (!sOutputStream.good()) throw runtime_error("Unable to initalize the Logger!");
  sInitialized = true;
}
