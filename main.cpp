#include <iostream>
#include "array_info.h"
int main(){
    int ar[]={9,5,1,4,6,7};
    int size=6;
    char t{9};
    selection_sort(ar,size,false);

    for (int i=0;i<size;i++){
        std::cout<<ar[i]<<" ";}
        selection_sort(ar,size,true);
        for (int i=0;i<size;i++){
            std::cout<<ar[i]<<" ";
        }
     std::cout<<"\n "<<std::endl;
    ShowElement(ar, size,  2, t);

}
