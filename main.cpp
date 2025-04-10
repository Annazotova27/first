#include <iostream>
#include "array_info.h"
 #include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

void printIntArray(const int* arr, int size) {
    std::cout << "[";
    for (int i = 0; i < size; i++) {
        std::cout << arr[i];
        if (i < size - 1) std::cout << ", ";
    }
    std::cout << "]" << std::endl;
}

void printProbabilityArray(const double* arr, int size) {
    std::cout << "Значение -> Вероятность:" << std::endl;
    for (int i = 0; i < size; i++) {
        if (arr[i] > 0) {
            std::cout << "  " << i << " -> " << std::fixed << std::setprecision(4) << arr[i] << std::endl;
        }
    }
}

void freeStatArray(StatArray& stat) {
    delete[] stat.ar;
    delete[] stat.probabilities;
}

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));
    
    int size1 = 10;
    int* array1 = new int[size1]{5, 5, 5, 10, 10, 20, 20, 20, 20, 30};
    
    std::cout << "Массив: ";
    printIntArray(array1, size1);
    
    StatArray stat1 = GetStatArray(array1, size1);
    
    std::cout << "\nИнформация о StatArray:" << std::endl;
    std::cout << "Размер исходного массива: " << stat1.size << std::endl;
    std::cout << "Размер массива вероятностей: " << stat1.size_prob << std::endl;
    std::cout << "Вероятности элементов:" << std::endl;
    printProbabilityArray(stat1.probabilities, stat1.size_prob);
    
    delete[] array1;
    freeStatArray(stat1);
    
    return 0;
}
 
  
  }
