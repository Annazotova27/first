#include <iostream>
#include "array_info.h"
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
