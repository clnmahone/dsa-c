#include <stdio.h>

struct Vector
{
    int size;
    int capacity;
    int *arr;
};

// void init(struct Vecotr *vecotr){
//     vecotr->size=0;

// }

void add(struct Vector *Arr, int data)
{

    if (Arr->size == Arr->capacity)
    {
        Arr->capacity *= 2;
        int arr[Arr->capacity];

        //array copy
        for (int i = 0; i < Arr->size; i++)
        {
            arr[i] = Arr->arr[i];
        }

        Arr->arr = arr;
    }

        int size = Arr->size;
        Arr->arr[size] = data;
        Arr->size++;

}

int del(struct Vector *Arr, int index)
{

    //shift left
    for (int i = index; i < Arr->size - 1; i++)
    {
        Arr->arr[i] = Arr->arr[i + 1];
    }
    Arr->size--;
    return Arr->arr[index];
}

int indexOf(struct Vector *Arr, int key)
{
    for (int i = 0; i < Arr->size; i++)
    {
        if (Arr->arr[i] == key)
        {
            return i;
        }
    }
    return -1;
}

void update(struct Vector *Arr, int index, int data)
{
    Arr->arr[index] = data;
}

void display(struct Vector *Arr)
{
    for (int i = 0; i < Arr->size; i++)
    {
        printf("%d ", Arr->arr[i]);
    }
    printf("\n");
}

int main()
{
    int arr[10];
    struct Vector
        array = {0, 10, arr};

    for (int i = 0; i < 10; i++)
    {
        add(&array, i);
    }
    display(&array);

    add(&array, 10);
	display(&array);

    return 0;
}
