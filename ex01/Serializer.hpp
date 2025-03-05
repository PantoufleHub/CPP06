#pragma once

#include <iostream>
#include <stdint.h>

typedef struct Data
{
	int id;
} Data;

class Serializer
{
	private:
		Serializer();
		~Serializer();

	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};
void displayData(Data *data);