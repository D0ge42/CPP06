#include <iostream>
#include <stdio.h>
#include "ScalarConverter.hpp"
#include "Info.hpp"

int main(int ac, char **av)
{
  if (ac != 2)
    return 0;
  Info info;
  info.inputParser(av[1]);
  ScalarConverter::convert(av[1]);
}
