#ifndef arreys.h
#define arreys.h

#include <stdio.h>

// --- 1. ВХОД И ИЗХОД (СКАН И ПРИНТ) ---

// Функция за въвеждане на елементи в масив
void scanArray(int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Елемент [%d] = ", i);
        scanf("%d", &a[i]);
    }
}

// Функция за принтиране на масив
void printArray(int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

// --- 2. СОРТИРАНЕ (ТРИТЕ ВИДА) ---

// Метод на мехурчето (Bubble Sort)
// 
void bubbleSort(int a[], int n) {
    int temp;
    for (int i = 0; i < n - 1; i++) {
        int sorted = 1;
        for (int k = 0; k < n - i - 1; k++) {
            if (a[k] > a[k + 1]) {
                temp = a[k]; a[k] = a[k + 1]; a[k + 1] = temp;
                sorted = 0;
            }
        }
        if (sorted) break;
    }
}

// Пряка селекция (Selection Sort)
// 
void selectionSort(int a[], int n) {
    int min, pos, temp;
    for (int i = 0; i < n - 1; i++) {
        pos = i;
        for (int k = i + 1; k < n; k++) {
            if (a[k] < a[pos]) pos = k;
        }
        temp = a[i]; a[i] = a[pos]; a[pos] = temp;
    }
}

// Пряко вмъкване (Insertion Sort)
// 
void insertionSort(int a[], int n) {
    int x, k;
    for (int i = 1; i < n; i++) {
        x = a[i];
        k = i - 1;
        while (k >= 0 && a[k] > x) {
            a[k + 1] = a[k];
            k--;
        }
        a[k + 1] = x;
    }
}

// --- 3. ТЪРСЕНЕ ---

// Последователно търсене (Linear Search)
int linearSearch(int a[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (a[i] == x) return i;
    }
    return -1;
}

// Двоично търсене (Binary Search) - само за сортирани масиви!
// 
int binarySearch(int a[], int n, int x) {
    int left = 0, right = n - 1, mid;
    while (left <= right) {
        mid = left + (right - left) / 2;
        if (a[mid] == x) return mid;
        if (a[mid] < x) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

// --- 4. СЛИВАНЕ (MERGE) ---
// Слива два сортирани масива (A и B) в трети масив (C)
// 
void mergeArrays(int a[], int n, int b[], int m, int c[]) {
    int i = 0, j = 0, k = 0;
    
    // Сравняваме елементите и взимаме по-малкия
    while (i < n && j < m) {
        if (a[i] < b[j]) {
            c[k++] = a[i++];
        } else {
            c[k++] = b[j++];
        }
    }
    
    // Добавяме останалите елементи, ако има такива
    while (i < n) c[k++] = a[i++];
    while (j < m) c[k++] = b[j++];
}

#endif