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
  unsigned long int dot_idx = content.find_first_not_of('.');

  if (dot_idx == std::string::npos && isdigit(str[i]) == true)
    this->data_type = T_INT;
  else if (dot_idx ==  std::string::npos && isdigit(str[i]) == false)
    this->data_type = T_CHAR;
  else if (dot_idx && isdigit(str[i]) == true && str[content.size()] == 'f')
    this->data_type = T_FLOAT;
  else if (dot_idx && isdigit(str[i]) == true && str[content.size()] != 'f')
    this->data_type = T_DOUBLE;
}

void Info::convertChar(const std::string &str)
{
  char c = str[0];
  if (isprint(c))
  {
    std::cout << "'c'"<< std::endl;
    std::cout << "int: " << static_cast<int>(c) << std::endl;
    std::cout << "double: " << static_cast<double>(c) << ".0"<< std::endl;
    std::cout << "float: " << static_cast<float>(c) << ".0f"<< std::endl;
  }
}


void Info::convertInt(const std::string &str)
{
  long int num = std::atoll(str.c_str());
  std::cout << "int: " << num << std::endl;
  std::cout << "char: " << static_cast<char>(num) << std::endl;
  std::cout << "double: " << static_cast<double>(num) << ".0"<< std::endl;
  std::cout << "float: " << static_cast<float>(num) << ".0f"<< std::endl;
}

void Info::convertFloat(const std::string &str)
{
  const char *cstring = str.c_str();
}

int Info::getDataType()
{
  return this->data_type;
}

Info::Info(void)
{
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

