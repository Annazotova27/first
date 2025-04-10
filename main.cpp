#include <iostream>
#include "array_info.h"
int main(int,char**){
      int *size=new int;
  int *number=new int;
  int *max=new int;
  int *min=new int;
  int *ar=new int [*size];
  ar= CreateAr(*size);
  delete[] ar;
  ar= CreateAr(*size,*number);
  delete[] ar;
  ar=CreateAr(*size,*max,*min);
  delete[] ar;
  delete size;
  delete number;
  delete max;
  delete min;
  
  
  }
