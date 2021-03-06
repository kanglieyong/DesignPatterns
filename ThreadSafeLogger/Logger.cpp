#include "Logger.h"
#include <stdexcept>
#include <cstddef>

using std::size_t;
using std::endl;
using std::string;
using std::vector;
using std::runtime_error;
using std::mutex;
using std::lock_guard;
using std::ofstream;
using std::ios_base;

const string Logger::kLogLevelDebug = "DEBUG";
const string Logger::kLogLevelError = "ERROR";
const string Logger::kLogLevelInfo = "INFO";
const char* const Logger::kLogFileName = "log.out";
Logger* Logger::pInstance = nullptr;

mutex Logger::sMutex;

Logger& Logger::instance()
{
  static Cleanup cleanup;
  lock_guard<mutex> gurad(sMutex);
  if (pInstance == nullptr) pInstance = new Logger();

  return *pInstance;
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
  lock_guard<mutex> guard(sMutex);
  logHelper(inMessage, inLogLevel);
}

void Logger::log(const vector<string>& inMessages, const string& inLogLevel)
{
  lock_guard<mutex> guard(sMutex);
  for (size_t i = 0; i < inMessages.size(); i++) logHelper(inMessages[i], inLogLevel);
}

void Logger::logHelper(const string& inMessage, const string& inLogLevel)
{
  mOutputStream << inLogLevel << ": " << inMessage << endl;
}

Logger::Cleanup::~Cleanup()
{
  lock_guard<mutex> guard(Logger::sMutex);
  delete Logger::pInstance;
  Logger::pInstance = nullptr;
}
