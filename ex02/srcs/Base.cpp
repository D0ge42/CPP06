#include "Base.hpp"
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <stddef.h>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *Base::generate()
{
  srand(time(NULL));
  int coinFlip = rand() % 3;
  if (coinFlip == 0)
    return new A();
  if (coinFlip == 1)
    return new B();
  if (coinFlip == 2)
    return new C();
  return NULL;
}

void Base::identify(Base *p)
{
  if (dynamic_cast<A*>(p))
    std::cout << "A" << std::endl;
  else if (dynamic_cast<B*>(p))
    std::cout << "B" << std::endl;
  else if (dynamic_cast<C*>(p))
    std::cout << "C" << std::endl;
}

void Base::identify(Base &p)
{
  if (dynamic_cast<A*>(&p))
    std::cout << "A" << std::endl;
  else if (dynamic_cast<B*>(&p))
    std::cout << "B" << std::endl;
  else if (dynamic_cast<C*>(&p))
    std::cout << "C" << std::endl;
}

Base::~Base()
{

}
