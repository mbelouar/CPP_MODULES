#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include <string>
# include <cstdint> 

struct Data {
    int value;
};

class Serializer
{
    private:
        Serializer();
    public:
        Serializer(Serializer const &src);
        Serializer &operator=(Serializer const &src);
        ~Serializer();

        static uintptr_t    serialize(Data* ptr);
        static Data*        deserialize(uintptr_t raw);
};

#endif