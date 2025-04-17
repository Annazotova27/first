#include <iostream>
#include "filo.h"
int main(){
    FILO* tf=new FILO();
    std::cout<<tf->ar<<std::endl;
    std::cout<<tf->size<<std::endl;
    std::cout<<tf->lastIndex<<std::endl;
    for (int i=0; i<100;i++){
        if (tf -> addToEnd(i)==-1){
            std::cout<<"el"<<i<<std::endl;
        }
    }
    for (int i=0;i<64; i++){
        std::cout<<tf->ar[i]<<std::endl;
    }
    for (int i=10;i<20;i++){
        tf ->getFromEnd(&i);
    }
    for (int i=0;i<64; i++){
        std::cout<<tf->ar[i]<<std::endl;

    }
    tf -> flush();
    std::cout<<tf -> ar;
    for (int i=0;i<64; i++){
        std::cout<<tf->ar[i]<<std::endl;

    }


}
