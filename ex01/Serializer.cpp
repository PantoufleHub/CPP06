#include "Serializer.hpp"

Serializer::Serializer()
{
	// std::cout << "Default Serializer constructor called" << std::endl;
}

Serializer::~Serializer ()
{
	// std::cout << "Default Serializer destructor called" << std::endl;
}

uintptr_t Serializer::serialize(Data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data *>(raw);
}

void displayData(Data *data)
{
	std::cout << "-- Data: --" << std::endl;
	std::cout << " - Id  : " << data->id << std::endl;
	// std::cout << " - Text: " << data->text << std::endl;
}
