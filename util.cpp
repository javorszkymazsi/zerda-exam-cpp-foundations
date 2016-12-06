#include <sstream>
#include "util.h"

std::string to_string(int integer) {
  std::stringstream ss;
  ss << integer;
  return ss.str();
}
