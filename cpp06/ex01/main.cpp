#include "Serialize.hpp"


int main()
{
	Data* originalPtr = new Data;
	originalPtr->id = 42;
	originalPtr->cont = "Hello, serialization!";

	std::cout << "Original Pointer Address:  " << originalPtr << std::endl;
	std::cout << "Original Data Content:     id=" << originalPtr->id << ", content=\"" << originalPtr->cont << "\"" << std::endl;
	std::cout << "-------------------------------------------" << std::endl;

	uintptr_t serializedValue = Serialize::serialize(originalPtr);
	std::cout << "Serialized Value (uintptr_t): " << serializedValue << std::endl;

	Data* deserializedPtr = Serialize::deserialize(serializedValue);
	std::cout << "Deserialized Pointer Address: " << deserializedPtr << std::endl;
	std::cout << "-------------------------------------------" << std::endl;

	if (originalPtr == deserializedPtr)
	{
		std::cout << "SUCCESS: The pointers match!" << std::endl;
		std::cout << "Deserialized Data Content: id=" << deserializedPtr->id << ", content=\"" << deserializedPtr->cont << "\"" << std::endl;
	}
	else
	{
		std::cout << "FAILURE: The pointers DO NOT match." << std::endl;
	}

	delete originalPtr;
	return 0;
}