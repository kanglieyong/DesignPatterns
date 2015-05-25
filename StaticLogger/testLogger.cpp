#include "Logger.h"
#include <string>
#include <vector>

using std::string;
using std::vector;

int main(void)
{
  Logger::log("testMessage", Logger::kLogLevelDebug);
  vector<string> items = {"item1", "item2"};
  Logger::log(items, Logger::kLogLevelError);
  Logger::teardown();
  
  return 0;
}
