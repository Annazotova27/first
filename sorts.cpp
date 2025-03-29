#include <iostream>
#include "sorts.h"


void insertion_sort(int* ar, int size, bool isAscending){
  if (isAscending==false){
  for(int i=1; i<size;i++){
    int k = ar[i];
    int j=i-1;
    while ( j>=0 && ar[j]>k ){
      ar[j+1]=ar[j];
      j=j-1;
    }
    ar[j+1]=k;
  }
  }
  else{
    for(int i=1; i<size;i++){
      int k = ar[i];
      int j=i-1;
      while ( j>=0 && ar[j]<k ){
        ar[j+1]=ar[j];
        j=j-1;
      }
      ar[j+1]=k;
    }
  }
}
void bubble_sort(int* ar, int size, bool isAscending){
  if (isAscending==false){
    for(int i=0; i<size;i++){
      for  (int j=0; j<size-1;j++){
      if (ar[j]>ar[j+1]){
        int a =ar[j];
        ar[j]=ar[j+1];
        ar[j+1]=a;
      }
      }

  }
}
else{
  for(int i=0; i<size;i++){
        for  (int j=0; j<size-1;j++){
        if (ar[j]<ar[j+1]){
          int a =ar[j];
          ar[j]=ar[j+1];
          ar[j+1]=a;
        }
        }

    }
  }
}
