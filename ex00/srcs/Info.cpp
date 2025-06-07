#include <cctype>
#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <ostream>
#include <string>
#include "Info.hpp"

void Info::detectType(char *str)
{
  if (str == NULL)
    return;
  std::string content = str;
  int i = 0;
  unsigned long int dot_idx = content.find_first_of('.');

  if (dot_idx == std::string::npos && isdigit(str[i]) == true)
  {
    this->data_type = T_INT;
    std::cout << "Int type" << std::endl;
  }
  else if (dot_idx ==  std::string::npos && isdigit(str[i]) == false)
  {
    this->data_type = T_CHAR;
    std::cout << "Char type" << std::endl;
  }
  else if (dot_idx && isdigit(str[i]) == true && str[content.size()- 1] == 'f')
  {
    this->data_type = T_FLOAT;
    std::cout << "Float type" << std::endl;
  }

  else if (dot_idx && isdigit(str[i]) == true && str[content.length() - 1] != 'f')
  {
    this->data_type = T_DOUBLE;
    std::cout << "Double type" << std::endl;
  }
}

void Info::convertChar(const std::string &str)
{
  char c = str[0];
  if (isprint(c))
  {
    std::cout << "'" << c << "'" << std::endl;
    std::cout << "int: " << static_cast<int>(c) << std::endl;
    std::cout << "double: " << static_cast<double>(c) << ".0"<< std::endl;
    std::cout << "float: " << static_cast<float>(c) << ".0f"<< std::endl;
  }
}


void Info::convertInt(const std::string &str)
{
  long long num = std::atoll(str.c_str());
  std::cout << "int: ";
  if (num < -2147483648)
    std::cout << "conversion not possible, intenger underflow" << std::endl;
  else if (num > 2147483647)
    std::cout << "conversion not possible, intenger overflow" << std::endl;
  else
    std::cout << num << std::endl;
  std::cout << "char: ";
  if (num > 0 && num < 127)
    std::cout << static_cast<char>(num) << std::endl;
  else
    std::cout << "not representable" << std::endl;
  std::cout << "double: " << static_cast<double>(num) << ".0"<< std::endl;
  std::cout << "float: " << static_cast<float>(num) << ".0f"<< std::endl;
}

void Info::convertFloat(const std::string &str)
{
  const char *cstring = str.c_str();
  float num = std::atof(cstring);
  std::cout << "char: ";
  if (num > 0 && num < 127)
    std::cout << static_cast<char>(num) << std::endl;
  else
    std::cout << "not representable" << std::endl;
  std::cout << "float: " << num << "0.f" << std::endl;
  std::cout << "int: " << num << std::endl;
  std::cout << "double: " << num << ".0" << std::endl;
}

void Info::convertDouble(const std::string &str)
{
  const char *cstring = str.c_str();
  float num = std::atof(cstring);
  std::cout << "char: ";
  if (num > 0 && num < 127)
    std::cout << static_cast<char>(num) << std::endl;
  else
    std::cout << "not representable" << std::endl;
  std::cout << "float: " << num << "0.f" << std::endl;
  std::cout << "int: " << num << std::endl;
  std::cout << "double: " << num << ".0" << std::endl;
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

