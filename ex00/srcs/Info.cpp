#include <cctype>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <ostream>
#include <string>
#include "Info.hpp"
#include "utils.h"


void Info::detectType(char *str)
{
  if (str == NULL)
    return;
  std::string content = str;
  int i = 0;
  unsigned long int dot_idx = content.find_first_of('.');

  if (is_special(str) == true)
    this->data_type = T_SPECIAL;
  else if (dot_idx == std::string::npos)
  {
    if (isdigit(str[i]) == true or (is_sign(str[i]) and isdigit(str[i + 1]) == true))
      this->data_type = T_INT;
    else
      this->data_type = T_CHAR;
  }
  else if ((dot_idx && isdigit(str[i]) == true) or (dot_idx and is_sign(str[i]) and isdigit(str[i + 1]) == true))
  {
    if (str[content.size() - 1] == 'f')
      this->data_type = T_FLOAT;
    else
      this->data_type = T_DOUBLE;
  }
}


void Info::convertChar(const std::string &str)
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
  char c = str[0];
  std::cout << "char: ";
  if (isScientificNotation(c) == false && isprint(c))
    std::cout << "'" << c << "'" << std::endl;
  else
    std::cout << "not displayable" << std::endl;
  std::cout << "int: " << static_cast<int>(c) << std::endl;
  if (is_there_dot(str) == true)
    std::cout << "double: " << static_cast<double>(c) << ".0"<< std::endl;
  else
    std::cout << "double: " << static_cast<double>(c) << std::endl;
  if (is_there_dot(str) == true)
    std::cout << "float: " << static_cast<float>(c) << ".0f"<< std::endl;
  else
    std::cout << "float: " << static_cast<float>(c) << "f" << std::endl;
}


void Info::convertInt(const std::string &str)
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
  long long num = std::atoll(str.c_str());
  std::cout << "int: ";
  if (num < -2147483648)
    std::cout << "conversion not possible, integer underflow" << std::endl;
  else if (num > 2147483648)
    std::cout << "conversion not possible, integer overflow" << std::endl;
  else
    std::cout << num << std::endl;
  std::cout << "char: ";
  if (isScientificNotation(num) == false && isprint(num))
    std::cout << static_cast<char>(num) << std::endl;
  else
    std::cout << "not representable" << std::endl;
  std::cout << "double: " << static_cast<double>(num) << ".0"<< std::endl;
  std::cout << "float: " << static_cast<float>(num) << ".0f"<< std::endl;
}

void Info::convertFloat(const std::string &str)
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
  const char *cstring = str.c_str();
  float num = std::atof(cstring);
  std::cout << "char: ";
  if (isScientificNotation(num) == false && isprint(num))
    std::cout << static_cast<char>(num) << std::endl;
  else
    std::cout << "not representable" << std::endl;
  if (is_there_dot(str) == true)
    std::cout << "double: " << static_cast<double>(num) << std::endl;
  else
    std::cout << "double: " << static_cast<double>(num) << ".0f" <<  std::endl;
  if (is_there_dot(str) == true)
    std::cout << "float: " << static_cast<float>(num) << "f"<< std::endl;
  else
    std::cout << "float: " << static_cast<float>(num) << ".0f" << std::endl;
  std::cout << "int: ";
  if (num < -2147483648)
    std::cout << "conversion not possible, integer underflow" << std::endl;
  else if (num > 2147483648)
    std::cout << "conversion not possible, integer overflow" << std::endl;
  else
    std::cout << static_cast<int>(num) << std::endl;
}

void Info::convertDouble(const std::string &str)
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
    std::cerr << "Invalid conversion, too many dots" << std::endl;
    exit(1);
  }
  const char *cstring = str.c_str();
  double num = std::atof(cstring);
  std::cout << "char: ";
  if (isScientificNotation(num) == false && isprint(num))
    std::cout << static_cast<char>(num) << std::endl;
  else
    std::cout << "not representable" << std::endl;
  std::cout << "int: ";
  if (num < -2147483648)
    std::cerr << "conversion not possible, integer underflow" << std::endl;
  else if (num > 2147483647)
    std::cerr << "conversion not possible, integer overflow" << std::endl;
  else
    std::cout << num << std::endl;
  if (is_there_dot(str) == true)
    std::cout << "double: " << static_cast<double>(num) << std::endl;
  else
    std::cout << "double: " << static_cast<double>(num) << ".0f" <<  std::endl;
  if (is_there_dot(str) == true)
      std::cout << "float: " << static_cast<float>(num) << "f"<< std::endl;
  else
    std::cout << "float: " << static_cast<float>(num) << ".0f" << std::endl;
}


void Info::convertSpecial(const std::string &str)
{
  if (str == "nan" || str == "nanf")
  {
      std::cerr << "char: impossible" << std::endl;
      std::cerr << "int: impossible" << std::endl;
      std::cerr << "float: nanf" << std::endl;
      std::cerr << "double: nan" << std::endl;
  }
  else if (str == "+inf" || str == "+inff")
  {
      std::cerr << "char: impossible" << std::endl;
      std::cerr << "int: impossible" << std::endl;
      std::cerr << "float: +inff" << std::endl;
      std::cerr << "double: +inf" << std::endl;
  }
  else if (str == "-inf" || str == "-inff")
  {
      std::cerr << "char: impossible" << std::endl;
      std::cerr << "int: impossible" << std::endl;
      std::cerr << "float: -inff" << std::endl;
      std::cerr << "double: -inf" << std::endl;
  }
}

int Info::getDataType()
{
  return this->data_type;
}

Info::Info(void)
{
  this->data_type = 0;
}

Info::Info(const Info &other)
{
  (void)other;
}

Info::~Info(void)
{
}

Info &Info::operator=(const Info &other)
{
  (void)other;
  return (*this);
}

