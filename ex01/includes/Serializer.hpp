#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <stdint.h>
#include "Data.h"


class Serializer
{
  private:
    Serializer(void);
  public:
    static uintptr_t serialize(Data *ptr);
    static Data *deserialize(uintptr_t raw);
    Serializer(const Serializer &other);
    ~Serializer(void);

    Serializer &operator=(const Serializer &other);
};


#endif
