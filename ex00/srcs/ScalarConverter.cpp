#include "ScalarConverter.hpp"
#include "Info.hpp"
#include <cctype>

void ScalarConverter::convert(char *str)
{
  Info info;
  std::string content;

  info.detectType(str);
  content = str;

  switch (info.getDataType())
  {
    case T_CHAR:
      info.convertChar(content);
      break;
    case T_INT:
      info.convertInt(content);
      break;
    case T_DOUBLE:
      info.convertDouble(content);
      break;
    case T_FLOAT:
      info.convertFloat(content);
      break;
  }
}

