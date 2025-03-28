#include "dz1.h"
#include <iostream>


int main(int, char**){
	int a[10];
	ShowNum_reverse(a, (sizeof(a)/sizeof(a[0])));
	ShowNum(a,(sizeof(a)/sizeof(a[0])));
	ShowEven(a,(sizeof(a)/sizeof(a[0])));
}




