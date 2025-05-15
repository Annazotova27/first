#ifndef SORT_H
#define SORT_H

/**
 * Заголовочный файл, содержащий объявления функций сортировки
 */

// Функции сортировки массивов целых чисел
void bubbleSort(int* ar, int size, bool isAscending);     //пузырьковая сортировка
void insertionSort(int* ar, int size, bool isAscending);  //сортировка вставками
void selectionSort(int* ar, int size, bool isAscending);  //сортировка выбором
void quickSort(int* ar, int size, bool isAscending);      //быстрая сортировка (сортировка Хоара)
void mergeSort(int* ar, int size, bool isAscending);      //сортировка слиянием

// Вспомогательные функции для алгоритмов быстрой сортировки и сортировки слиянием
void quickSortRecursive(int* ar, int low, int high, bool isAscending);
int partition(int* ar, int low, int high, bool isAscending);
void mergeSortRecursive(int* ar, int left, int right, bool isAscending);
void merge(int* ar, int left, int mid, int right, bool isAscending);

#endif // SORT_H

