#ifndef LOGGER_H_
#define LOGGER_H_

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

class Logger
{
 public:
  static const std::string kLogLevelDebug;
  static const std::string kLogLevelInfo;
  static const std::string kLogLevelError;

  static void log(const std::string& inMessage, const std::string& inLogLevel);
  static void log(const std::vector<std::string>& inMessages, const std::string& inLogLevel);
  
  static void teardown();
  
 protected:
  static void init();
  static const char* const kLogFileName;
  static bool sInitialized;
  static std::ofstream sOutputStream;
  
 private:
  Logger() {}
};

#endif
