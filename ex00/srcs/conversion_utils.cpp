#include <algorithm>
#include <cctype>
#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <ostream>
#include <string>
#include "Info.hpp"

int is_sign(char c);
int is_special(const std::string &str);
int is_there_dot(const std::string &str);

int is_special(const std::string &str)
{
  if (str == "nan" || str == "nanf" || str == "+inf"
      || str == "+inff" || str == "-inf" || str == "-inff")
    return 1;
  return 0;
}

int is_sign(char c)
{
  if (c == '+' || c == '-')
    return 1;
  return 0;
}

int is_there_dot(const std::string &str)
{
  size_t dot_idx = str.find_first_of('.');
  if (dot_idx == std::string::npos)
    return 0;
  return 1;
}

