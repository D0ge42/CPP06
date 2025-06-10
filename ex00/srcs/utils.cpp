#include "utils.h"
#include <cctype>
#include <cstddef>
#include <cstdlib>
#include <limits>
#include <string>

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

int isAlphaString(const std::string &str)
{
  const char *to_check = str.c_str();
  while(*(to_check))
  {
    if (isalpha(*to_check) == false)
      return 0;
    to_check++;
  }
  return 1;
}

int dotCount(const std::string &str)
{
  const char *to_check = str.c_str();
  size_t dot_count = 0;
  while(*(to_check))
  {
    if (*to_check == '.')
      dot_count++;
    to_check++;
  }
  return dot_count;
}

int signCount(const std::string &str)
{
  const char *to_check = str.c_str();
  size_t sign_count = 0;
  while(*(to_check))
  {
    if (is_sign(*to_check) == true)
      sign_count++;
    to_check++;
  }
  return sign_count;
}

int isStringAlphaNum(const std::string &str)
{
  const char *to_check = str.c_str();
  int i = 0;
  while(to_check[i])
  {
    if (to_check[i] != 'f'
        && std::isalpha(to_check[i])
        && is_sign(to_check[i]) == false
        && to_check[i] != '.')
      return 1;
    i++;
  }
  return 0;
}

int isScientificNotation(long double num)
{
  if (num > 999999 || num < 999999)
    return 1;
  return 0;
}

int check_int_limits(long double num)
{
  if (num > std::numeric_limits<int>::max())
    return 1;
  if (num < std::numeric_limits<int>::min())
    return 1;
  return 0;
}

int check_float_limits(long double num)
{
  if (num > std::numeric_limits<float>::max())
    return (1);
  if (num < std::numeric_limits<float>::min())
    return (1);
  return 0;
}

int check_double_limits(long double num)
{
  if (num > std::numeric_limits<double>::max())
    return 1;
  if (num < std::numeric_limits<double>::min())
    return 1;
  return 0;
}
