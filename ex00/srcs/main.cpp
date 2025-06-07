#include <iostream>
#include <stdio.h>
#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
  (void)ac;
  ScalarConverter::convert(av[1]);
}
