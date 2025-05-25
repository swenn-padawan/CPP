#include <iostream>
#include <stdint.h>

typedef struct s_data{
	std::string data;
}	Data;

class Serializer{

public:
	static 	uintptr_t serialize(Data *ptr);
	static Data	*deserialize(uintptr_t raw);
private:
	Serializer();
	Serializer(const Serializer &copy);
	Serializer &operator=(const Serializer &src);
	~Serializer();
};

#define UNUSED(x) (void(x));
