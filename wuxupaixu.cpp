#include <stdio.h>  
#include <stdlib.h>  
#include <time.h>  
  
typedef struct {  
    int *elements;  
    int size;  
    int capacity;  
} DynamicArray;  
  
void initDynamicArray(DynamicArray *array, int initialCapacity) {  
    array->elements = (int *)malloc(initialCapacity * sizeof(int));  
    if (!array->elements) {  
        fprintf(stderr, "Memory allocation failed\n");  
        exit(EXIT_FAILURE);  
    }  
    array->size = 0;  
    array->capacity = initialCapacity;  
}  
  
void insert(DynamicArray *array, int element) {  
    if (array->size == array->capacity) {  
        array->capacity *= 2;  
        array->elements = (int *)realloc(array->elements, array->capacity * sizeof(int));  
        if (!array->elements) {  
            fprintf(stderr, "Memory reallocation failed\n");  
            exit(EXIT_FAILURE);  
        }  
    }  
    array->elements[array->size++] = element;  
}  
  
void freeDynamicArray(DynamicArray *array) {  
    free(array->elements);  
    array->elements = NULL;  
    array->size = array->capacity = 0;  
}  
  
void printDynamicArray(const DynamicArray *array) {  
    for (int i = 0; i < array->size; i++) {  
        printf("%d ", array->elements[i]);  
    }  
    printf("\n");  
}  
  
void update(DynamicArray *array, int position, int newValue) {  
    if (position < 0 || position >= array->size) {  
        fprintf(stderr, "Invalid position\n");  
        return;  
    }  
    array->elements[position] = newValue;  
}  
  
void remove(DynamicArray *array, int position) {  
    // 你的remove函数实现已经正确  
}  
  
void mix(DynamicArray *array) {  
    // 你的mix函数实现已经正确  
}  
  
int min(const DynamicArray *array) {  
    // 你的min函数实现已经正确  
}  
  
int partition(int arr[], int left, int right) {  
    int pivot = arr[right];  
    int i = left - 1;  
    for (int j = left; j < right; j++) {  
        if (arr[j] <= pivot) {  
            i++;  
            int temp = arr[i];  
            arr[i] = arr[j];  
            arr[j] = temp;  
        }  
    }  
    int temp = arr[i + 1];  
    arr[i + 1] = arr[right];  
    arr[right] = temp;  
    return i + 1;  
}  
  
int Quick_Select(int arr[], int left, int right, int k) {  
    // 你的Quick_Select函数实现已经正确  
}  
  
int main() {  
    srand(time(NULL));  
  
    DynamicArray myArray;  
    initDynamicArray(&myArray, 5);  
  
    // 插入一些元素  
    insert(&myArray, 3);  
    insert(&myArray, 1);  
    insert(&myArray, 4);  
    insert(&myArray, 1);  
    insert(&myArray, 5);  
  
    // 打印原始数组  
    printDynamicArray(&myArray);  
  
    // 更新位置为2的元素为2  
    update(&myArray, 2, 2);  
    printf("After updating element at position 2 to 2: ");  
    printDynamicArray(&myArray);  
  
    // 接下来的操作与你的代码相同  
    // ...  
  
    return 0;  
}
