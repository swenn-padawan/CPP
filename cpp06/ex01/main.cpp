#include "Serializer.hpp"

int main(){
	Data data;

	data.data = "I am the data";
	std::cout << "Data = " << &data <<" and data.data = " << data.data << std::endl;
	uintptr_t ptr = Serializer::serialize(&data);
	Data *dataPtr = Serializer::deserialize(ptr);
	std::cout << "ptr = " << ptr << std::endl;
	std::cout << "dataPtr = " << dataPtr->data << std::endl;

}
