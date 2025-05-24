#pragma once

template<typename T>
void	iter(T *array, int size, void (*func)(T &)){
	for (int i = 0; i < size; i++){
		func(array[i]);
	}
}
template<typename T>
void	iter(T *array, int size, void (*func)(const T &)){
	for (int i = 0; i < size; i++){
		func(array[i]);
	}
}
template<typename T>
void	iter(T *array, int size, void (*func)(T)){
	for (int i = 0; i < size; i++){
		func(array[i]);
	}
}
