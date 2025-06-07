#include "ScalarConverter.hpp"
#include "Info.hpp"
#include <cctype>
#include <iostream>
#include <ostream>

void ScalarConverter::convert(char *str)
{
  Info info;
  std::string content;

  info.detectType(str);
  content = str;
  int data_type = info.getDataType();
  std::cout << data_type << std::endl;
  switch (data_type)
  {
    case T_CHAR:
      info.convertChar(content);
      break;
    case T_INT:
      info.convertInt(content);
      break;
    case T_FLOAT:
      info.convertFloat(content);
      break;
    case T_DOUBLE:
      info.convertDouble(content);
      break;
    case T_SPECIAL:
      info.convertSpecial(content);
      break;
    default:
      std::cout << "invalid conversion" << std::endl;
  }
}

