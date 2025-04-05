#include <iostream>
#include "array_info.h"
#include <map>
struct MinMax GetMaxMin(const int* ar, int size){
    struct MinMax a={0,0};
    int mn=ar[0];
    int mx=ar[0];
    for (int i=0; i<size;i++){
        if (*(ar+i)<mn){
            mn=*(ar+i);
            a.ind_min=i;
        }
        if (*(ar+i)>mx){
            mx=*(ar+i);
            a.ind_max=i;
        }
    }
    return a;
}
struct CountNum GetStatNumber(const int* ar, int size){
    struct CountNum b={0,0,0};
    for (int i=0;  i<size;i++){
        if (*(ar+i)>0){
            b.pos+=1;
        }
        else if (*(ar+i)==0){
            b.zero+=1;
        }
        else  {
            b.neg+=1;
        }
    }
    return b;
}
void getInfoArray(struct ArrayInfo* arInfo){
    struct MinMax a=GetMaxMin(arInfo->ar,arInfo->size);
    arInfo->ind_max=a.ind_max;
    arInfo->ind_min=a.ind_min;
    for (int i=0; i<arInfo->size;i++){
        arInfo->mean+=(double)arInfo->ar[i]/(double)arInfo->size;
    }





}
int* CreateAr(int size){
  return new int[size];
}
int* CreateAr(int size, int number){
  int *ar=new int[size];
  int *i = new int;
  *i=0;
  while (*i<size){
    *(ar+*i)=number;
    (*i)++;
  }
  delete  i;
 return ar;

}
int* CreateAr(int size, int min, int max){
  srand(time(nullptr));
    int *ar=new int[size];
    int *i = new int;
    *i=0;
    while (*i<size){
      *(ar+*i)=rand()%(max-min+1)+min;
      (*i)++;
    }
    delete  i;
    return  ar;

  }
#include "array_info.h"
#include <algorithm>


struct StatArray GetStatArray(const int* ar, int size) {
    StatArray result;
    
    
    result.size = size;
    result.ar = new int[size];
    for (int i = 0; i < size; i++) {
        result.ar[i] = ar[i];
    }
    
    
    int max_element = 0;
    for (int i = 0; i < size; i++) {
        if (ar[i] > max_element) {
            max_element = ar[i];
        }
    }
    
    
    result.size_prob = max_element + 1;
    result.probabilities = new double[result.size_prob];
    
    
    for (int i = 0; i < result.size_prob; i++) {
        result.probabilities[i] = 0.0;
    }
    
    
    for (int i = 0; i < size; i++) {
        if (ar[i] < result.size_prob) {
            result.probabilities[ar[i]] += 1.0;
        }
    }
    
    
    for (int i = 0; i < result.size_prob; i++) {
        if (result.probabilities[i] > 0) {
            result.probabilities[i] /= size;
        }
    }
    
    return result;
}

