#include <iostream>
struct ArrayInfo {
int* ar;
int size;
int ind_max;
int ind_min;
double mean;
};

void getInfoArray(struct ArrayInfo* arInfo){
  int  a,b,c;
  double d;
  std::cin>>a;
   int array[a];
  b=0;
  c=a-1;
  d=0.1;
 //std::cout<<array;
std::cout<<std::endl<<b<<c<<d;
  for (int i=0;i<a; i++){
    int q;
    std::cin>>q;
    array[i]=q;
    
  }
  double q{0};
  for (int i=0;i<a; i++){
    q+=array[i];
    
  }
  d=q/a;
  std::cout<<d;
  arInfo->ar=array;
   arInfo->size=a;
  arInfo->ind_max=c;
   arInfo->ind_min=a;
   arInfo->mean=d;
}
struct MinMax {
int ind_min;
int ind_max;
};
struct MinMax GetMaxMin(const int* ar, int size){
  int mx{-10000000};
  int mn{100000000};
  for (int i=0; i<size;i++){
    if (ar[i] >mx){
      mx=ar[i];}
      if (ar[i] <mn){
        mn=ar[i];
      }
    
  }
  MinMax.ind_min=mn;
   MinMax.ind_max=mx;
}

int main(){
  ArrayInfo anna;
  getInfoArray(&anna);
  //std::cout<<anna.mean;
  
}

