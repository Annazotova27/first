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
struct StatArray GetStatArray(const int* ar, int size) {
    StatArray result;
    if (size > MAX_ARRAY_SIZE) {
        size = MAX_ARRAY_SIZE;
    }
    result.size = size;
    for (int i = 0; i < size; i++) {
        result.ar[i] = ar[i];
    }
    std::map<int, int> frequency;
    for (int i = 0; i < size; i++) {
        frequency[ar[i]]++;
    }
    result.size_prob = size;

    for (int i = 0; i < size; i++) {
        result.probabilities[i] = static_cast<double>(frequency[ar[i]]) / size;
    }

    return result;
}
