#ifndef LOGGER_H_
#define LOGGER_H_

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class Logger
{
 public:
  static Logger& instance();

  void log(const std::string& inMessage, const std::string& inLogLevel);
  void log(const std::vector<std::string>& inMessages, const std::string& inLogLevel);

  static const std::string kLogLevelDebug;
  static const std::string kLogLevelInfo;
  static const std::string kLogLevelError;

 protected:
  static Logger sInstance;

  static const char* const kLogFileName;
  std::ofstream mOutputStream;
  
 private:
  Logger();
  virtual ~Logger();
};

#endif
