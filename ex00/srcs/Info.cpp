#include <cctype>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <ostream>
#include <string>
#include "Info.hpp"
#include "checks.hpp"
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
  parseChar(str);
  char c = str[0];
  std::cout << "char: ";
  if (c >= 32 && c < 127)
    std::cout << "'" << c << "'" << std::endl;
  else
    std::cout << "not displayable" << std::endl;
  std::cout << "int: " << static_cast<int>(c) << std::endl;
  std::cout << "double: " << static_cast<double>(c) << ".0"<< std::endl;
  std::cout << "float: " << static_cast<float>(c) << ".0f"<< std::endl;
}


void Info::convertInt(const std::string &str)
{
  parseInt(str);
  long double num = std::strtold(str.c_str(),NULL);
  bool dotZeroFlag = (static_cast<int>(num) == num && num < 1e6 && (num > 1e-5 || num == 0));
  std::cout << "int: ";
  if (check_int_limits(num) == true)
    std::cerr << "conversion not possible, integer overflow/underflow" << std::endl;
  else
    std::cout << static_cast<int>(num) << std::endl;
  std::cout << "char: ";
  if (num < 0 || num > 127)
    std::cerr << "conversion not possible: char overflow/underflow" << std::endl;
  else if (num >= 32 && num < 127)
    std::cout << static_cast<char>(num) << std::endl;
  else
    std::cout << "not representable" << std::endl;
  if (check_double_limits(num) == true)
    std::cerr << "double: conversion not possible, double underflow/overflow" << std::endl;
  else
  {
    if (dotZeroFlag == true)
      std::cout << "double: " << static_cast<double>(num) << ".0"<< std::endl;
    else
      std::cout << "double: " << static_cast<double>(num) << std::endl;
  }
  if (check_float_limits(num) == true)
    std::cerr << "float: conversion not possible, float underflow/overflow" << std::endl;
  else
  {
    if (dotZeroFlag == true)
      std::cout << "float: " << static_cast<float>(num) << ".0f"<< std::endl;
    else
      std::cout << "float: " << static_cast<float>(num) << "f" << std::endl;
  }
}

void Info::convertFloat(const std::string &str)
{
  parseFloatOrDouble(str);
  long double num = std::strtold(str.c_str(),NULL);
  bool dotZeroFlag = (static_cast<int>(num) == num && num < 1e6 && (num > 1e-5 || num == 0));
  std::cout << "char: ";
  if (num < 0 || num > 127)
    std::cerr << "conversion not possible: char overflow/underflow" << std::endl;
  else if (num >= 32 && num < 127)
    std::cout << static_cast<char>(num) << std::endl;
  else
    std::cout << "not representable" << std::endl;
  if (check_double_limits(num) == true)
    std::cerr << "double: conversion not possible, double underflow/overflow";
  else if (dotZeroFlag == false)
    std::cout << "double: " << static_cast<double>(num) << std::endl;
  else
      std::cout << "double: " << static_cast<double>(num) << ".0" <<  std::endl;
  if (check_float_limits(num) == true)
    std::cerr << "float: conversion not possible, float underflow/overflow";
  else if (dotZeroFlag == false)
    std::cout << "float: " << static_cast<float>(num) << "f"<< std::endl;
  else
      std::cout << "float: " << static_cast<float>(num) << ".0f" << std::endl;
  std::cout << "int: ";
  if (check_int_limits(num) == true)
    std::cerr << "conversion not possible, integer overflow/underflow" << std::endl;
  else
    std::cout << static_cast<int>(num) << std::endl;
}

void Info::convertDouble(const std::string &str)
{
  parseFloatOrDouble(str);
  long double num = std::strtold(str.c_str(),NULL);
  bool dotZeroFlag = (static_cast<int>(num) == num && num < 1e6 && (num > 1e-5 || num == 0));
  std::cout << "char: ";
  if (num < 0 || num > 127)
    std::cerr << "conversion not possible: char overflow/underflow" << std::endl;
  else if (num >= 32 && num < 127)
    std::cout << static_cast<char>(num) << std::endl;
  else
    std::cout << "not representable" << std::endl;
  std::cout << "int: ";
  if (check_int_limits(num) == true)
    std::cerr << "conversion not possible, integer overflow/underflow" << std::endl;
  else
    std::cout << static_cast<int>(num) << std::endl;
  if (check_double_limits(num) == true)
    std::cerr << "conversion not possible, double overflow/underflow" << std::endl;
  else if (dotZeroFlag == true)
      std::cout << "double: " << static_cast<double>(num) << ".0" <<  std::endl;
  else
    std::cout << "double: " << static_cast<double>(num) << std::endl;
  if (check_float_limits(num) == true)
    std::cerr << "conversion not possible, float overflow/underflow" << std::endl;
  else if (dotZeroFlag == false)
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

