#include <iostream>
#include "dz1.h"
using namespace std;
int main(){
  const int size=3;   
  int ar[size];
      for (int i = 0;i<size;i++ )
      {
          cout<<"Введите число №"<<i+1<<"-> ";
          cin>>ar[i];
          cout<<endl;
      }
  cout<<endl;
  ShowNum_reverse(ar,size);
  cout<<endl;
  ShowNum(ar, size);
  cout<<endl;
  ShowEven(ar, size);
  cout<<endl;
}

 


