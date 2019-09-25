#include<stdio.h>
#include"data_struct.h"
int main()
{
    //init
    Vector v;
    vector_init(&v, 10);
    //fill
    for (int i = 0; i < 10; i++)
        vector_add(&v, i);
    vector_add(&v, 10);
    vector_insert(&v, 4, 99);
    vector_remove(&v,5);
    //show
    vector_show(&v);

    printf("%d", vector_indexOf(&v, 4));

    return 0;
}