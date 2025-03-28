#include "dz1.h"
#include <iostream>

void ShowNum_reverse (const int* array, std::size_t size_ar){
	for (int i = size_ar-1; i > 0; i--){
		std::cout << array [i] << '\t';
	}
	
	std::cout << array [0] << '\n';

}

void ShowNum (const int* array, std::size_t size_ar){
	for (int i = 0; i < size_ar-1; i++){
		std::cout << array [i] << '\t';
	}
			
	std::cout << array [size_ar-1] << '\n';
}

void ShowEven (const int* array, std::size_t size_ar){
	for (int i = 0; i < size_ar-1; i++){
		if ((array [i] & (0x01)) == 0){
			std::cout << array[i] << '\t';
		}
	}			
	if ((array [size_ar-1] & (0x01)) == 0){
		std::cout << array[size_ar-1];
	}	
}



 

