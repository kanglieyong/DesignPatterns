#include "Logger.h"
#include <string>
#include <vector>

using std::string;
using std::vector;

int main(void)
{
  Logger::instance().log("test message", Logger::kLogLevelDebug);
  vector<string> items = {"item1", "item2"};
  Logger::instance().log(items, Logger::kLogLevelError);
  
  return 0;
}
