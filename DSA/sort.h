//sort.h
#ifndef _SORT
#define _SORT

/*O(n2)*/
void select_sort(int *arr, int n);
void bubble_sort(int *arr, int n);
void insert_sort(int *arr, int n);
/*less than O(n2)*/
void shell_short(int arr[], int n);
/*O(nlogn)*/
void merge_sort(int *arr, int l, int r);
void quick_sort(int arr[], int left, int right);
void heap_sort(int arr[], int n);
/*O(d(n+rd))   r-记录个数 d-记录中最大关键字数*/
void radix_sort(int* arr,int n);
/*util*/
void heapfy(int arr[], int n, int i);
int partition2(int arr[], int left, int right);
void merge(int *arr, int l, int m, int r);
void swap(int *x, int *y);
void print(int *arr, int n);

#endif