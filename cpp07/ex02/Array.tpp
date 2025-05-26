#include "Array.hpp"

template<typename T>
Array<T>::Array(void): array(NULL), _size(0){}

template<typename T>
Array<T>::Array(unsigned int n): array(NULL), _size(n){
	if (n == 0)
		return;
	array = new T[n]();
	_size = n;
}

template<typename T>
Array<T>::Array(const Array<T> &src){
  array = new T[src.size()];
  _size = src.size();
  for (size_t i = 0; i < src._size; i++)
	  array[i] = src.array[i];
}

template<typename T>
Array<T>::~Array(void) {
	delete[] array;
}

template<typename T>
Array<T> &Array<T>::operator=(const Array<T> &src) {
  if (this == &src)
    return (*this);
  if (array) delete[] array;
  _size = src._size;
  array = new T[_size];
  std::memcpy(array, src.array, sizeof(T) * _size);
  return (*this);
}
template <typename T>
size_t	Array<T>::size() const {
	return (_size);
}

template <typename T>
T & Array<T>::operator [] (unsigned int index){
	if (index >= _size)
		throw OutofRangeException();
	return (array[index]);
}

template <typename T>
const T & Array<T>::operator [] (unsigned int index) const{
	if (index >= _size)
		throw OutofRangeException();
	return (array[index]);
}

template <typename T>
std::ostream & operator << (std::ostream & ostream, const Array<T> & array)
{
	for (size_t i = 0; i < array.size(); ++i)
		ostream << array[i] << '\n';
	return ostream;
}
