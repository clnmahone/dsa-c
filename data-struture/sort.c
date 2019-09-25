#include <stdio.h>
#include "sort.h"
//print the arr
void print(int arr[], int n)
{
    int *p = arr;
    for (p; p < arr + n; p++)
        printf("%d ", *p);
}
//swap two
void swap(int *x, int *y)
{
    int t = 0;
    t = *x;
    *x = *y;
    *y = t;
}

/**
 * bubble sort
 * the simple method and easy to think of
 * 
*/
void bubble_sort(int *arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        //for every complete for-loop, one element is sorted at the right,
        //form 0 to n-1-i
        for (int j = 0; j < n - i - 1; j++)
        {
            //compare every adjacent element and swap if neccesary
            if (arr[j] > arr[j + 1])
                swap(arr + j, arr + j + 1);
        }
    }
}
/**
 * select sort
 * 
*/
void select_sort(int *arr, int n)
{
    int minIndex = 0;
    for (int i = 0; i < n - 1; i++)
    {
        //select the min element form the remaining part
        minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
                minIndex = j;
        }
        //swap current element and the min
        swap(arr + i, arr + minIndex);
    }
}

/**
 * using divide and conquer strategy,
 * divide the sequence to sorted and unsorted part,
 * and move the element from unsorted part into sorted part
 * 
*/
void insert_sort(int *arr, int n)
{
    int markedIdex = 0;
    int markedVal = 0;
    //from a[1]
    for (int i = 1; i < n; i++)
    {
        //the first element in the unsorted part
        markedIdex = i;
        markedVal = arr[i];
        //for sorted part
        for (int j = i - 1; j >= 0; j--)
        {
            if (markedVal < arr[j])
            {
                //right move
                arr[j + 1] = arr[j];
                //remember the index
                markedIdex = j;
            }
        }
        //insert tne marked element in the sorted part
        arr[markedIdex] = markedVal;
    }
}

//merge sot
void merge_sort(int arr[], int l, int r)
{

    if (l < r)
    {
        //the medium position
        int m = l + (r - l) / 2;
        merge_sort(arr, l, m);
        merge_sort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

void merge(int arr[], int l, int m, int r)
{
    //arr------the array
    //l/m/r----left/medium/right

    //the left/right partion lenght
    int l_len = m - l + 1;
    int r_len = r - m;
    int L[l_len], R[r_len];

    int i, j, k;
    // divid the array into L/R array
    for (i = 0; i < l_len; i++)
        L[i] = arr[l + i];
    for (j = 0; j < r_len; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    //merge L & R
    while (i < l_len && j < r_len)
    {
        if (L[i] < R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    //copy the remaining element in L or R
    while (i < l_len)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < r_len)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

/**shell sort
 * application: C stdlib sort
 * Shellsort is not stable: (it may change the relative order of elements with equal values). 
 * It executes faster when the input is partially sorted.
*/

void shell_short(int *arr, int n)
{

    //delt sequence n, n/2, ..., 0
    for (int delt = n; delt > 0; delt /= 2)
    {
        //i:dlet...n
        for (int i = delt; i < n; i++)
        {
            int makedVal=arr[i];
            int j;
            for (j = i; j >= delt && arr[j-delt] > makedVal; j -= delt)
                arr[j]=arr[j-delt];
            arr[j]=makedVal;
        }
    }
}

/**
 * quick sort
 * key point is qvoit
 */

void quick_sort(int arr[], int left, int right)
{

    if (left < right)
    {
        int pivot = partition2(arr, left, right);
        quick_sort(arr, left, pivot - 1);
        quick_sort(arr, pivot + 1, right);
    }
}

//from geeks for geeks
int partition(int arr[], int left, int right)
{
    //chose the last one as pivot
    int pivot = arr[right];
    //k---the pivot position is should be at
    int k = left - 1;
    for (int i = left; i <= right - 1; i++)
    {
        if (arr[i] < pivot)
        {
            //swap the element which less than povit to the left
            k++;
            swap(&arr[k], &arr[i]);
        }
    }
    //swap the povit to the position it should be at
    swap(&arr[k + 1], &arr[right]);
    //return the index the povit should be at
    return k + 1;
}

//form 数据结构-yanweimin
int partition2(int arr[], int low, int high)
{
    int pivot = arr[high];
    while (low < high)
    {
        while (low < high && arr[low] <= pivot)
            low++;
        arr[high] = arr[low];
        while (low < high && arr[high] >= pivot)
            high--;
        arr[low] = arr[high];
    }
    arr[low] = pivot;
    return low;
}

/**
 * heap sort
 * 1.what is a heap?
 * heap is a kinde of binary tree, in whitch the parent is always
 * bigger(or smaller) than children.
 * 
 * 2.how to storage a heap in an array?
 * put them in a array by the natural sort
 * parent i--->Lchild 2*i+1, Rchild 2*i+2;
 * child j --->parent (j-1)/2;
 * 
 * 3.how to heapfy?
 * form the last no-leaf node(index (n-1)/2)
 * 
 * 4.time complexity
 * average O(nlogn)
 * worst O(nlogn)
 * 
*/

void heap_sort(int arr[], int n)
{
    //heapfy the array first,
    //form the last no-leaf node (n-1)/2 to the root.
    for (int i = (n - 1) / 2; i >= 0; i--)
        heapfy(arr, n, i);
    //take out the root and put it in the right of the array.
    for (int i = n - 1; i >= 0; i--)
    {
        //remove the root to the last of the aray,
        //and put the last leaf to the root.
        swap(&arr[0], &arr[i]);
        //after move the last lead node to the root,
        //heapfy the array again.
        heapfy(arr, i, 0);
    }
}

void heapfy(int *arr, int n, int i)
{
    //arr---the array addr
    //n-----the array length
    //i-----the heapfy start point

    //for parent i, the l/rchild is
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    //assum the min node is i
    int min = i;

    //1.l or r < n, to guarantee i the not the leaf node
    //2.find the min node
    if (l < n && arr[l] < arr[min])
        min = l;
    if (r < n && arr[r] < arr[min])
        min = r;
    // if i is not the min node
    if (min != i)
    {
        //swap the nim child with its parent
        swap(&arr[min], &arr[i]);
        //when swap happend, the min child value changed,
        //it maybe destroy the heap(the child sub-tree changed),
        //so we heapy form the min child position.
        heapfy(arr, n, min);
    }
}

// A function to do counting sort of arr[] according to 
// the digit represented by exp. 
void countSort(int arr[], int n, int exp) 
{ 
    int output[n]; // output array 
    int i, count[10] = {0}; 
  
    // Store count of occurrences in count[] 
    for (i = 0; i < n; i++) 
        count[ (arr[i]/exp)%10 ]++; 
  
    //前面有几个比 arr[i]小的数，在加一。
    for (i = 1; i < 10; i++) 
        count[i] += count[i - 1]; 
  
    // Build the output array 
    for (i = n - 1; i >= 0; i--) 
    { 
        //把arr[i]放到output中合适位置（前面有几个比他小）
        output[count[ (arr[i]/exp)%10 ] - 1] = arr[i]; 
        //比自己小的个数减一。
        count[ (arr[i]/exp)%10 ]--; 
    } 
  
    // Copy the output array to arr[], so that arr[] now 
    // contains sorted numbers according to current digit 
    for (i = 0; i < n; i++) 
        arr[i] = output[i]; 
} 

// A utility function to get maximum value in arr[] 
int getMax(int arr[], int n) 
{ 
    int mx = arr[0]; 
    for (int i = 1; i < n; i++) 
        if (arr[i] > mx) 
            mx = arr[i]; 
    return mx; 
} 

void radix_sort(int* arr, int n)
{
    // Find the maximum number to know number of digits 
    int m = getMax(arr, n); 
  
    // Do counting sort for every digit. Note that instead 
    // of passing digit number, exp is passed. exp is 10^i 
    // where i is current digit number 
    for (int exp = 1; m/exp > 0; exp *= 10) 
        countSort(arr, n, exp); 
}

int main()
{

    int arr[] = {4, 7, 1, 89, 56, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    //bubble_sort(arr, n);
    //insert_sort(arr, n);
    //merge_sort(arr, 0, n - 1);
    //shell_short(arr, n);
    quick_sort(arr, 0, n - 1);
    //heap_sort(arr, n);
    //radix_sort(arr,n);
    print(arr, n);
    return 0;
}