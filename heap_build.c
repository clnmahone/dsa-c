#include <stdio.h>

/**
 * to build a heap from array
 * 
 * 
*/


void print(int arr[], int n);
int *min(int x, int y);
void swap(int *x, int *y);
void HeapConstruct(int *a, int n);


int main()
{
    int a[] = {10, 6, 3, 8, 7,1};
    int n = sizeof(a) / sizeof(a[0]);
    HeapConstruct(a, n);
    print(a, n);
    return 0;
}
//构建小根堆
//to-do:有问题
void HeapConstruct(int *a, int n)
{   
    //从堆最后一个元素开始
    int *minIndex;
    if (n / 2 != 0)
        minIndex = a + n - 1;
    else
        minIndex = min(a[n - 1], a[n - 2]);
    //小于父节点，交换
    if (*minIndex < a[(n - 1) / 2])
        swap(a + (minIndex - a) / 4, a+(n-1)/2);

    for (int i = (n - 1) / 2 - 1; i >= 0; i--)
    {
        minIndex = min(a[i * 2 + 1], a[i * 2 + 2]);
        if (*minIndex < a[i])
            swap(a + (minIndex - a) / 4, a + i);
    }
}

int *min(int x, int y) { return x < y ? &x : &y; }
void swap(int *x, int *y)
{
    int t = 0;
    t = *x;
    *x = *y;
    *y = t;
}
void print(int arr[], int n)
{
    int *p = arr;
    for (p; p < arr + n; p++)
        printf("%d ", *p);
}