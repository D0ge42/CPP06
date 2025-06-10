#include "Serializer.hpp"
#include <iostream>

int main()
{
  Data data;
  data.c = 'c';
  data.num = 42;
  uintptr_t ptr = Serializer::serialize(&data);
  Data *ptr1 = Serializer::deserialize(ptr);
  std::cout << &ptr << std::endl;
  std::cout << ptr1 << std::endl;
}
