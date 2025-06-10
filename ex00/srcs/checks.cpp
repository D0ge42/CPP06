#include "checks.hpp"
#include <cctype>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <limits>
#include <ostream>
#include <string>
#include "Info.hpp"
#include "utils.h"


void parseChar(const std::string &str)
{
  const char *to_check = str.c_str();
  if (is_sign(*to_check) && isdigit(*(to_check + 1)) == false)
  {
    std::cerr << "Conversion not valid" << std::endl;
    exit(1);
  }
  if (str.length() > 1 && isAlphaString(str) == true)
  {
    std::cerr << "Conversion not valid" << std::endl;
    exit(1);
  }
}


void parseInt(const std::string &str)
{
  if (isStringAlphaNum(str) == true)
  {
    std::cerr << "Conversion is invalid. Num should only contain digits, dot or sign" << std::endl;
    exit(1);
  }
  if (signCount(str) > 1)
  {
    std::cerr << "Conversion is invalid. Too many signs" << std::endl;
    exit(1);
  }
}

void parseFloatOrDouble(const std::string &str)
{
  if (isStringAlphaNum(str) == true)
  {
    std::cerr << "Conversion is invalid. Num should only contain digits, dot or sign" << std::endl;
    exit(1);
  }
  if (signCount(str) > 1)
  {
    std::cerr << "Conversion is invalid. Too many signs" << std::endl;
    exit(1);
  }
  if (dotCount(str) > 1)
  {
    std::cerr << "Invalid conversion\n, too many dots" << std::endl;
    exit(1);
  }
}
