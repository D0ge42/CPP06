#include "Serializer.hpp"
#include <iostream>

int main()
{
  Data data;
  data.c = 'c';
  data.num = 42;


  std::cout << "\033[1;91mBefore reinterpret cast \033[0m" << std::endl;
  std::cout << data.c << std::endl;
  std::cout << data.num << std::endl;
  std::cout << &data << std::endl;

  // Reinterpret cast

  uintptr_t ptr = Serializer::serialize(&data);
  Data *ptr1 = Serializer::deserialize(ptr);


  std::cout << "\033[1;92mAfter reinterpret cast \033[0m" << std::endl;
  std::cout << ptr1->c << std::endl;
  std::cout << ptr1->num << std::endl;
  std::cout << ptr1 << std::endl;
}
