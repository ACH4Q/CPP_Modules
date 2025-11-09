#ifndef SERIALIZE_HPP
#define SERIALIZE_HPP

#include "Data.hpp"
#include <cstdint>

class Serialize
{
private:
    Serialize();
    Serialize(const Serialize& other);
    Serialize operator=(const Serialize& other);
    ~Serialize();
public:
    uintptr_t serialize(Data* ptr);
    Data* deserialize(uintptr_t raw);
};


#endif