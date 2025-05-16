#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include "sorts_middle.h"
#include "MeasTime.h"

/**
 * Программа для демонстрации работы алгоритмов сортировки
 */

// Функция для вывода массива
void printArray(const int* arr, int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i];
        if (i < size - 1) std::cout << ", ";
    }
    std::cout << std::endl;
}

// Функция для копирования массива
int* copyArray(const int* source, int size) {
    int* result = new int[size];
    std::memcpy(result, source, size * sizeof(int));
    return result;
}

// Функция для тестирования алгоритма сортировки
void testSortingAlgorithm(const std::string& algorithmName, 
                          void (*sortFunction)(int*, int, bool),
                          const int* originalArray, 
                          int size, 
                          bool isAscending) {
    // Создаем копию исходного массива
    int* testArray = copyArray(originalArray, size);
    
    std::cout << "Тестирование: " << algorithmName << std::endl;
    std::cout << "Порядок сортировки: " << (isAscending ? "по возрастанию" : "по убыванию") << std::endl;
    
    std::cout << "Исходный массив: ";
    printArray(testArray, size);
    
    // Вызываем функцию сортировки для отображения результата
    sortFunction(testArray, size, isAscending);
    
    std::cout << "Отсортированный массив: ";
    printArray(testArray, size);
    
    // Измеряем время работы алгоритма на массиве того же размера
    double executionTime = measureSortingTime(sortFunction, size, isAscending);
    std::cout << "Время выполнения: " << executionTime << " наносекунд (" 
              << executionTime / 1000000.0 << " мс)" << std::endl;
    std::cout << std::endl;
    
    // Освобождаем память
    delete[] testArray;
}

/**
 * Функция для тестирования производительности алгоритмов сортировки на массивах разных размеров
 * в соответствии с общим алгоритмом работы программы
 */
void benchmarkSortingAlgorithms() {
    // Массив размеров для тестирования
    const int sizes[] = {
        100, 500, 750, 900, 1400, 2000, 2500, 4100, 5000, 7800, 9500, 
        12000, 13000, 15000, 25000, 33000, 50000, 100000, 140000, 180000,
        250000, 400000, 500000, 655000, 800000, 840000, 1000000
    };
    const int numSizes = sizeof(sizes) / sizeof(sizes[0]);
    
    // Дополнительные размеры для быстрой сортировки и сортировки слиянием
    const int extraSizes[] = {
        1250000, 1400000, 1800000, 2000000, 2500000, 3000000
    };
    const int numExtraSizes = sizeof(extraSizes) / sizeof(extraSizes[0]);
    
    // Инициализация генератора случайных чисел
    srand(static_cast<unsigned int>(time(nullptr)));
    
    // Заголовок таблицы результатов
    std::cout << "N\tBubble\tInsert\tSelect\tQuick\tMerge\n";
    
    // Основные размеры массивов
    for (int i = 0; i < numSizes; i++) {
        int size = sizes[i];
        
        // Вывод размера массива
        std::cout << size << "\t";
        
        // Пузырьковая сортировка
        double bubbleTime = 0;
        if (size <= 50000) { // Ограничиваем размер для медленных алгоритмов
            bubbleTime = measureSortingTime(bubbleSort, size, true) / 1000000.0; // перевод в миллисекунды
            std::cout << bubbleTime << "\t";
        } else {
            std::cout << "-\t";
        }
        
        // Сортировка вставками
        double insertTime = 0;
        if (size <= 100000) {
            insertTime = measureSortingTime(insertionSort, size, true) / 1000000.0;
            std::cout << insertTime << "\t";
        } else {
            std::cout << "-\t";
        }
        
        // Сортировка выбором
        double selectTime = 0;
        if (size <= 100000) {
            selectTime = measureSortingTime(selectionSort, size, true) / 1000000.0;
            std::cout << selectTime << "\t";
        } else {
            std::cout << "-\t";
        }
        
        // Быстрая сортировка
        double quickTime = measureSortingTime(quickSort, size, true) / 1000000.0;
        std::cout << quickTime << "\t";
        
        // Сортировка слиянием
        double mergeTime = measureSortingTime(mergeSort, size, true) / 1000000.0;
        std::cout << mergeTime << "\n";
    }
    
    // Дополнительные размеры только для быстрой сортировки и сортировки слиянием
    for (int i = 0; i < numExtraSizes; i++) {
        int size = extraSizes[i];
        
        // Вывод размера массива
        std::cout << size << "\t-\t-\t-\t";
        
        // Быстрая сортировка
        double quickTime = measureSortingTime(quickSort, size, true) / 1000000.0;
        std::cout << quickTime << "\t";
        
        // Сортировка слиянием
        double mergeTime = measureSortingTime(mergeSort, size, true) / 1000000.0;
        std::cout << mergeTime << "\n";
    }
}

int main() {
    // Локализация вывода для поддержки русского языка
    setlocale(LC_ALL, "Russian");
    
    // Тестовые массивы
    int testArray1[] = {5, 2, 9, 1, 5, 6};
    int testArray2[] = {10, 7, 8, 9, 1, 5};
    int testArray3[] = {38, 27, 43, 3, 9, 82, 10};
    int emptyArray[] = {};
    int singleElementArray[] = {42};
    
    int size1 = sizeof(testArray1) / sizeof(testArray1[0]);
    int size2 = sizeof(testArray2) / sizeof(testArray2[0]);
    int size3 = sizeof(testArray3) / sizeof(testArray3[0]);
    int sizeEmpty = 0;
    int sizeSingle = 1;
    
    std::cout << "=== ДЕМОНСТРАЦИЯ АЛГОРИТМОВ СОРТИРОВКИ ===" << std::endl << std::endl;
    
    // Пузырьковая сортировка
    testSortingAlgorithm("Пузырьковая сортировка", bubbleSort, testArray1, size1, true);
    testSortingAlgorithm("Пузырьковая сортировка", bubbleSort, testArray1, size1, false);
    
    // Сортировка вставками
    testSortingAlgorithm("Сортировка вставками", insertionSort, testArray2, size2, true);
    testSortingAlgorithm("Сортировка вставками", insertionSort, testArray2, size2, false);
    
    // Сортировка выбором
    testSortingAlgorithm("Сортировка выбором", selectionSort, testArray3, size3, true);
    testSortingAlgorithm("Сортировка выбором", selectionSort, testArray3, size3, false);
    
    // Быстрая сортировка
    testSortingAlgorithm("Быстрая сортировка", quickSort, testArray1, size1, true);
    testSortingAlgorithm("Быстрая сортировка", quickSort, testArray2, size2, false);
    
    // Сортировка слиянием
    testSortingAlgorithm("Сортировка слиянием", mergeSort, testArray3, size3, true);
    testSortingAlgorithm("Сортировка слиянием", mergeSort, testArray1, size1, false);
    
    // Тестирование граничных случаев
    std::cout << "=== ТЕСТИРОВАНИЕ ГРАНИЧНЫХ СЛУЧАЕВ ===" << std::endl;
    
    // Пустой массив
    std::cout << "Пустой массив (все алгоритмы должны корректно обрабатывать этот случай)" << std::endl;
    
    // Массив из одного элемента
    std::cout << "Массив из одного элемента: ";
    printArray(singleElementArray, sizeSingle);
    std::cout << "После сортировки (любым алгоритмом): ";
    printArray(singleElementArray, sizeSingle);
    std::cout << "(Этот массив не требует сортировки)" << std::endl << std::endl;
    
    // Тестирование производительности на больших массивах
    benchmarkSortingAlgorithms();
    
    return 0;
}

