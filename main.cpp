#include <iostream>
#include "array_info.h"
int main(int,char**){
    const int size{10};
    int a[size];
    struct ArrayInfo arInfo;
    arInfo.ar = &a[0];
    arInfo.size = size;
    getInfoArray(&arInfo);
    GetStatNumber(arInfo.ar, arInfo.size);
 CreateAr(size,min,max);

}



