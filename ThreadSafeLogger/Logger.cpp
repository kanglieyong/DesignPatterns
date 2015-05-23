#include "Logger.h"

using std::string;

const string Logger::kLogLevelDebug = "DEBUG";
const string Logger::kLogLevelInfo = "INFO";
const string Logger::kLogLevelError = "ERROR";

const char* const Logger::kLogFileName = "log.out";

Logger* Logger::pInstance = nullptr;
mutex Logger::aMutex;

Logger& Logger::instance()
{
  static Cleanup cleanup;
  lock_guard<mutex> guard(sMutex);
  if (pInstance == nullptr) pInstance = new Logger();
  
  return *pInstance;
}

Logger::Cleanup::~Cleanup()
{
  lock_guard<mutex> guard(Logger::sMutex);
  delete Logger::pInstance;
  Logger::pInstance = nullptr;
}

Logger::Logger()
{
  mOutputStream.open(kLogFileName, ios_base::app);
  if (!mOutputStream.good()) throw runtime_error("Unable to initialize the Logger!");
}

Logger::~Logger()
{
  mOutputStream.close();
}

void Logger::log(const string& inMessage, const string& inLogLevel)
{
  lock_guard<mutex> guard(sMutex);
  logHelper(inMessage, inLogLevel);
}

void Logger::log(const vector<string>& inMessages, const string& inLogLevel)
{
  lock_guard<mutex> guard(sMutex);
  for (size_t i = 0; i < inMessages.size(); i++) logHelper(inMessages[i], inLogLevel);
}

void Logger::logHelper(const std::string& inMessage, const std::string& inLogLevel)
{
  mOutputStream << inLogLevel << ": " << inMessage << endl;
}