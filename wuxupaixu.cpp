#include <stdio.h>  
#include <stdlib.h>  
  
// 自定义的min和max函数（虽然在这个例子中max函数可能不被直接使用）  
int min(int a, int b) {  
    return (a < b) ? a : b;  
}  
  
// 交换数组中的两个元素  
void swap(int *a, int *b) {  
    int temp = *a;  
    *a = *b;  
    *b = temp;  
}  
  
// 划分函数  
int partition(int arr[], int low, int high) {  
    int pivot = arr[high];  
    int i = (low - 1);  
    for (int j = low; j < high; j++) {  
        if (arr[j] <= pivot) {  
            i++;  
            swap(&arr[i], &arr[j]);  
        }  
    }  
    swap(&arr[i + 1], &arr[high]);  
    return (i + 1);  
}  
  
// QuickSelect函数  
int quickSelect(int arr[], int low, int high, int k) {  
    if (k > 0 && k <= high - low + 1) {  
        int index = partition(arr, low, high);  
        if (index - low == k - 1)  
            return arr[index];  
        if (index - low > k - 1)  
            return quickSelect(arr, low, index - 1, k);  
        return quickSelect(arr, index + 1, high, k - index + low - 1);  
    }  
    return INT_MIN; // 假设k不在范围内时返回一个不可能的最小值（应包含limits.h）  
}  
  
// 找到数组中的最大值（简单遍历）  
int findMax(int arr[], int n) {  
    int maxValue = arr[0];  
    for (int i = 1; i < n; i++) {  
        if (arr[i] > maxValue) {  
            maxValue = arr[i];  
        }  
    }  
    return maxValue;  
}  
  
// 打印数组的函数  
void printArray(int arr[], int size) {  
    for (int i = 0; i < size; i++) {  
        printf("%d ", arr[i]);  
    }  
    printf("\n");  
}  
  
int main() {  
    int arr[] = {12, 23, 22, 11, 9, 3, 4, 5};  
    int n = sizeof(arr) / sizeof(arr[0]);  
    int minValue, maxValue;  
  
    // 使用QuickSelect找最小值  
    minValue = quickSelect(arr, 0, n - 1, 1);  
  
    // 简单遍历找最大值  
    maxValue = findMax(arr, n);  
  
    printf("Minimum value: %d\n", minValue);  
    printf("Maximum value: %d\n", maxValue);  
    printf("Array: ");  
    printArray(arr, n);  
  
    return 0;  
}