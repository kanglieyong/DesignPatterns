#include "Logger.h"
#include <string>
#include <vector>

using std::string;
using std::vector;

int main(void)
{
  Logger::instance().log("Test", Logger::kLogLevelDebug);
  vector<string> items = {"Item 1", "Item 2"};
  Logger::instance().log(items, Logger::kLogLevelError);

  return 0;
}
