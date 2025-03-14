#include <iostream>
#include "dz1.h"
using namespace std;
void ShowNum_reverse(const int* array, size_t size_ar){
  for (int i = size_ar; i >=0; i--){
    cout<<array[i]<<'\t';
  }
}
  void ShowNum(const int* array, size_t size_ar){
    for (int i=0; i<size_ar; i++){
      cout<<array[i]<<'\t';
    }
  }
void ShowEven(const int* array, size_t size_ar){
  for (int i=0; i<size_ar ; i++){
    if (array[i]==array[i]/2*2){
      cout<<array[i]<<'\t';
    }
  }
}



 

