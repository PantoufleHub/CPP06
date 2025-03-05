#include "Serializer.hpp"

int main()
{
	Data data;
	data.id = 123456789;

	displayData(&data);

	uintptr_t serptr = Serializer::serialize(&data);
	std::cout << "Serialized: " << serptr << std::endl;

	Data *dataptr = Serializer::deserialize(serptr);
	std::cout << "Deserialized: " << dataptr << std::endl;

	displayData(&data);

	return 0;
}
