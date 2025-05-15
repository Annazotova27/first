#include "MeasTime.h"
#include "sort_middle.h"
#include <cstdlib>  // для rand()

/**
 * Реализация функций для измерения времени выполнения алгоритмов сортировки
 */

/**
 * Функция для измерения времени работы алгоритма сортировки
 * в соответствии с общим алгоритмом работы программы
 */
double measureSortingTime(void (*sortFunction)(int*, int, bool), 
                         int size, 
                         bool isAscending) {
    // 1. Выделяем память под размер массива
    int* arr = new int[size];
    
    // 2. Заполняем массив случайными числами
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 1000000;
    }
    
    // 3. Получаем текущее время (start)
    auto start = std::chrono::high_resolution_clock::now();
    
    // 4. Выполняем функцию сортировки (сортируем по возрастанию)
    sortFunction(arr, size, isAscending);
    
    // 5. Получаем текущее время (end)
    auto end = std::chrono::high_resolution_clock::now();
    
    // 6. Вычисляем разницу времени (end - start) в наносекундах
    double duration_time = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
    
    // 7. Выводим время сортировки на экран (будет осуществляться в основной функции)
    
    // 8. Освобождаем память
    delete[] arr;
    
    return duration_time;
}
