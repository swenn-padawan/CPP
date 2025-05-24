#pragma once

template<typename T>
void	ft_iter(T *array, int size, void (*func)(T &)){
	for (int i = 0; i < size; i++){
		func(array[i]);
	}
}
