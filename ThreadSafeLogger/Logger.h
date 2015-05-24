#ifndef LOGGERH_H_
#define LOGGERH_H_

#include <string>
#include <vector>
#include <fstream>
#include <mutex>

class Logger
{
 public:
  static const std::string kLogLevelDebug;
  static const std::string kLogLevelError;
  static const std::string kLogLevelInfo;

  static Logger& instance();

  void log(const std::string& inMessage, const std::string& inLogLevel);
  void log(const std::vector<std::string>& inMessages, const std::string& inLogLevel);
  
 protected:
  static Logger* pInstance;
  static const char* const kLogFileName;
  std::ofstream mOutputStream;

  friend class Cleanup;
  class Cleanup
  {
  public:
    ~Cleanup();
  };

  void logHelper(const std::string& inName, const std::string& inLogLevel);
  
 private:
  Logger();
  virtual ~Logger();
  
  Logger(const Logger& src);
  Logger& operator=(const Logger& rhs);

  static std::mutex sMutex;
};

#endif
