#include "Logger.h"
#include <stdexcept>

// using std::string;
// using std::vector;
// using std::runtime_error;

using namespace std;

const string Logger::kLogLevelDebug = "DEBUG";
const string Logger::kLogLevelInfo = "INFO";
const string Logger::kLogLevelError = "ERROR";

const char* const Logger::kLogFileName = "log.out";

Logger Logger::sInstance;

Logger& Logger::instance()
{
  return sInstance;
}

Logger::~Logger()
{
  mOutputStream.close();
}

Logger::Logger()
{
  mOutputStream.open(kLogFileName, ios_base::app);
  if (!mOutputStream.good()) throw runtime_error("Unable to initialize the Logger!");
}

void Logger::log(const string& inMessage, const string& inLogLevel)
{
  mOutputStream << inLogLevel << ": " << inMessage << endl;
}

void Logger::log(const vector<string>& inMessages, const string& inLogLevel)
{
  for (size_t i = 0; i < inMessages.size(); i++) {
    log(inMessages[i], inLogLevel);
  }
}
