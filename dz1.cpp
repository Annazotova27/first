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
  for (int i=0; i<size_ar;i++){
    if (array[i]==array[i]/2*2){
      cout<<array[i]<<'\t';
    }
  }
}

int main(){
  const int size=3;   
  int ar[size];
      for (int i=0;i<size;i++ )
      {
          cout<<"Введите число №"<<i+1<<"-> ";
          cin>>ar[i];
          cout<<endl;
      }
  cout<<endl;
  ShowNum_reverse(ar, size);
  cout<<endl;
  ShowNum(ar, size);
  cout<<endl;
  ShowEven(ar, size);
  cout<<endl;
}

 

