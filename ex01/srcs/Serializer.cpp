#include "Serializer.hpp"

uintptr_t Serializer::serialize(Data *ptr)
{
  return reinterpret_cast<uintptr_t>(ptr);
}

Data *Serializer::deserialize(uintptr_t raw)
{
  return reinterpret_cast<Data*>(raw);
}

Serializer::Serializer(void)
{
}

Serializer::Serializer(const Serializer &other)
{
  (void)other;
}

Serializer::~Serializer(void)
{
}

Serializer &Serializer::operator=(const Serializer &other)
{
  (void)other;
  return (*this);
}
