#include "Base.hpp"
#include <iostream>

int main()
{
  Base base;
  Base *ptr = base.generate();
  std::cout << "Ptr --> Generated base is of type:";
  base.identify(ptr);
  std::cout << "Ref --> Generated base is of type:";
  base.identify(*ptr);
}
