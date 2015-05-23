#ifndef LOGGER_H_
#define LOGGER_H_

#include <string>
#include <vector>

class Logger
{
 public:
  static Logger& instance();
  
  static const std::string kLogLevelDebug;
  static const std::string kLogLevelInfo;
  static const std::string kLogLevelError;

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

  void logHealper(const std::string& inMessage, const std::string& inLogLevel);
  
 private:
  Logger();
  virtual ~Logger();
  static std::mutex sMutex;
  
  Logger(const Logger& src);
  Logger& operator(const Logger& rhs);
};

#endif
