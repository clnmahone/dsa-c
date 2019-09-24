#include<stdio.h>

int main(){

    int arr[]={1,8,8,3,4,8,2,0,7,7,5};
    int *p;
    p=arr;
    int temp;
    int length=sizeof(arr)/4;
    for(int i = 0; i < length/2; i++)
    {
        temp = *(p+i);
        *(p+i)=*(p+length-1-i);
        *(p+length-1-i)=temp;
    }

    for(; p <(arr+11); p++)
    {
        printf("%d",*p);
    }
    
    
    return 0;
}
