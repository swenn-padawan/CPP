#include "Serializer.hpp"

Serializer::Serializer()
{}

Serializer::Serializer(const Serializer & toCopy)
{
	UNUSED(toCopy);
}

Serializer::~Serializer()
{}

Serializer & Serializer::operator = (const Serializer & toAssign)
{
	UNUSED(toAssign);
	return *this;
}

uintptr_t Serializer::serialize(Data *ptr){
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data *Serializer::deserialize(uintptr_t raw){
	return (reinterpret_cast<Data *>(raw));
}
