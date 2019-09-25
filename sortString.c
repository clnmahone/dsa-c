#include<stdio.h>

void print(char *arr[],int n);
void sort(char *arr[],int n);

int main(){
    //一个指针数组，元素为每个字符串的首地址
    char *arr[]={"china","boy","girl"};
    int n=3;
    sort(arr,n);
    print(arr,n);
    return 0;
}

void print(char *arr[],int n){
    while(n--){
        printf("%s\n",*arr++);
    }

}

void sort(char *arr[],int n){
    char *t;
    int i,j;
    for( i = 0; i < n-1; i++)
    {
        for( j = i+1; j < n; j++)
        {
            if (**(arr+i)>**(arr+j)) {
                t=arr[i];
                arr[i]=arr[j];
                arr[j]=t;
            }
            
        }
        
    }
    
}
