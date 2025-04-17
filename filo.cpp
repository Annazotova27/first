#include <iostream>
#include "filo.h"
FILO::FILO(){
   size = 64;
  ar = new int[size];
   
   lastIndex=0;
}
FILO::FILO(int s){
    size = s;
  ar = new int[size];
  
   lastIndex=0;
}
FILO::~FILO(){
  delete [] ar;
}
int  FILO::addToEnd(int element){
  if (lastIndex==size){
    return -1;
  }
  *(ar+lastIndex)=element;
  lastIndex++;
  return 0;
}
int FILO::getFromEnd(int* element){
  if (lastIndex==0){
    return -1;
  }
 ar[lastIndex]=0;
  lastIndex--;
  return 0;
   
}
void FILO::flush(){
 for (int i{0};i<size;i++){
   ar[i]=0;
 }
  
}

