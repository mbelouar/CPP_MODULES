#include "Serializer.hpp"

int main() {
    Data data;
    data.value = 105;

    Data* originalPtr = &data;

    uintptr_t raw = Serializer::serialize(originalPtr);
    std::cout << "Serialized value (uintptr_t): " << raw << std::endl;

    Data* deserializedPtr = Serializer::deserialize(raw);
    std::cout << "Deserialized value (Data*)  : " << deserializedPtr->value << std::endl;

    if (deserializedPtr == originalPtr) {
        std::cout << "==> Success: The deserialized pointer is equal to the original pointer!" << std::endl;
    } else {
        std::cout << "==> Error: The deserialized pointer is not equal to the original pointer!" << std::endl;
    }

    return 0;
}