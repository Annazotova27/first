#include "array_info.h"
#include <iostream>

struct MinMax GetMinMax( const int* ar, int size){
	struct MinMax temp  = {0,0};
	int min =ar[0];
	int max = ar[0];
	for (int i=0; i<size;i++){
		if (min >*(ar+i)){
			min =*(ar+i);


