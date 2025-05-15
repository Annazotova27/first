#include "sort_middle.h"
#include <iostream>
#include <cstring> // для memcpy

/**
 * Реализация различных алгоритмов сортировки
 */

// Вспомогательная функция для обмена элементов массива
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

/**
 * Пузырьковая сортировка
 * 
 * @param ar указатель на массив целых чисел
 * @param size размер массива
 * @param isAscending флаг сортировки (true - по возрастанию, false - по убыванию)
 */
void bubbleSort(int* ar, int size, bool isAscending) {
    // Проверка на пустой массив или массив из одного элемента
    if (ar == nullptr || size <= 1) return;
    
    for (int i = 0; i < size - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < size - i - 1; j++) {
            // Сравнение с учетом типа сортировки (по возрастанию или убыванию)
            bool shouldSwap = isAscending ? (ar[j] > ar[j + 1]) : (ar[j] < ar[j + 1]);
            if (shouldSwap) {
                swap(ar[j], ar[j + 1]);
                swapped = true;
            }
        }
        // Если за проход не было обменов, массив уже отсортирован
        if (!swapped) break;
    }
}

/**
 * Сортировка вставками
 * 
 * @param ar указатель на массив целых чисел
 * @param size размер массива
 * @param isAscending флаг сортировки (true - по возрастанию, false - по убыванию)
 */
void insertionSort(int* ar, int size, bool isAscending) {
    // Проверка на пустой массив или массив из одного элемента
    if (ar == nullptr || size <= 1) return;

    for (int i = 1; i < size; i++) {
        int key = ar[i];
        int j = i - 1;
        
        // Определение условия сравнения в зависимости от типа сортировки
        bool shouldContinue = isAscending ? (j >= 0 && ar[j] > key) : (j >= 0 && ar[j] < key);
        
        // Смещение элементов, которые больше/меньше key (в зависимости от типа сортировки)
        while (shouldContinue) {
            ar[j + 1] = ar[j];
            j--;
            shouldContinue = isAscending ? (j >= 0 && ar[j] > key) : (j >= 0 && ar[j] < key);
        }
        ar[j + 1] = key;
    }
}

/**
 * Сортировка выбором
 * 
 * @param ar указатель на массив целых чисел
 * @param size размер массива
 * @param isAscending флаг сортировки (true - по возрастанию, false - по убыванию)
 */
void selectionSort(int* ar, int size, bool isAscending) {
    // Проверка на пустой массив или массив из одного элемента
    if (ar == nullptr || size <= 1) return;

    for (int i = 0; i < size - 1; i++) {
        int extremumIndex = i;
        
        for (int j = i + 1; j < size; j++) {
            // Поиск минимального/максимального элемента в зависимости от типа сортировки
            bool shouldUpdate = isAscending ? (ar[j] < ar[extremumIndex]) : (ar[j] > ar[extremumIndex]);
            if (shouldUpdate) {
                extremumIndex = j;
            }
        }
        
        // Если нашли новый минимум/максимум, меняем элементы местами
        if (extremumIndex != i) {
            swap(ar[i], ar[extremumIndex]);
        }
    }
}

/**
 * Разделение массива для быстрой сортировки
 * 
 * @param ar указатель на массив целых чисел
 * @param low нижняя граница подмассива
 * @param high верхняя граница подмассива
 * @param isAscending флаг сортировки
 * @return индекс опорного элемента
 */
int partition(int* ar, int low, int high, bool isAscending) {
    int pivot = ar[high]; // Опорный элемент
    int i = low - 1; // Индекс меньшего элемента
    
    for (int j = low; j < high; j++) {
        // Условие сравнения в зависимости от типа сортировки
        bool shouldSwap = isAscending ? (ar[j] <= pivot) : (ar[j] >= pivot);
        if (shouldSwap) {
            i++;
            swap(ar[i], ar[j]);
        }
    }
    
    swap(ar[i + 1], ar[high]);
    return i + 1;
}

/**
 * Рекурсивная часть быстрой сортировки
 * 
 * @param ar указатель на массив целых чисел
 * @param low нижняя граница подмассива
 * @param high верхняя граница подмассива
 * @param isAscending флаг сортировки
 */
void quickSortRecursive(int* ar, int low, int high, bool isAscending) {
    if (low < high) {
        // Разделение массива и получение индекса опорного элемента
        int pivotIndex = partition(ar, low, high, isAscending);
        
        // Рекурсивная сортировка левой и правой частей
        quickSortRecursive(ar, low, pivotIndex - 1, isAscending);
        quickSortRecursive(ar, pivotIndex + 1, high, isAscending);
    }
}

/**
 * Быстрая сортировка (алгоритм Хоара)
 * 
 * @param ar указатель на массив целых чисел
 * @param size размер массива
 * @param isAscending флаг сортировки (true - по возрастанию, false - по убыванию)
 */
void quickSort(int* ar, int size, bool isAscending) {
    // Проверка на пустой массив или массив из одного элемента
    if (ar == nullptr || size <= 1) return;
    
    quickSortRecursive(ar, 0, size - 1, isAscending);
}

/**
 * Слияние двух отсортированных подмассивов
 * 
 * @param ar указатель на массив целых чисел
 * @param left индекс начала первого подмассива
 * @param mid индекс конца первого подмассива
 * @param right индекс конца второго подмассива
 * @param isAscending флаг сортировки
 */
void merge(int* ar, int left, int mid, int right, bool isAscending) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    // Создание временных массивов
    int* L = new int[n1];
    int* R = new int[n2];
    
    // Копирование данных во временные массивы
    for (int i = 0; i < n1; i++)
        L[i] = ar[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = ar[mid + 1 + j];
    
    // Слияние временных массивов обратно в ar[left..right]
    int i = 0, j = 0, k = left;
    
    while (i < n1 && j < n2) {
        bool condition = isAscending ? (L[i] <= R[j]) : (L[i] >= R[j]);
        if (condition) {
            ar[k] = L[i];
            i++;
        } else {
            ar[k] = R[j];
            j++;
        }
        k++;
    }
    
    // Копирование оставшихся элементов L[], если они есть
    while (i < n1) {
        ar[k] = L[i];
        i++;
        k++;
    }
    
    // Копирование оставшихся элементов R[], если они есть
    while (j < n2) {
        ar[k] = R[j];
        j++;
        k++;
    }
    
    // Освобождение памяти
    delete[] L;
    delete[] R;
}

/**
 * Рекурсивная часть сортировки слиянием
 * 
 * @param ar указатель на массив целых чисел
 * @param left индекс начала подмассива
 * @param right индекс конца подмассива
 * @param isAscending флаг сортировки
 */
void mergeSortRecursive(int* ar, int left, int right, bool isAscending) {
    if (left < right) {
        // Находим середину массива
        int mid = left + (right - left) / 2;
        
        // Сортируем первую и вторую половины
        mergeSortRecursive(ar, left, mid, isAscending);
        mergeSortRecursive(ar, mid + 1, right, isAscending);
        
        // Слияние отсортированных половин
        merge(ar, left, mid, right, isAscending);
    }
}

/**
 * Сортировка слиянием
 * 
 * @param ar указатель на массив целых чисел
 * @param size размер массива
 * @param isAscending флаг сортировки (true - по возрастанию, false - по убыванию)
 */
void mergeSort(int* ar, int size, bool isAscending) {
    // Проверка на пустой массив или массив из одного элемента
    if (ar == nullptr || size <= 1) return;
    
    mergeSortRecursive(ar, 0, size - 1, isAscending);
}

