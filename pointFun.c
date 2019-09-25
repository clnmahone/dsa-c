#include<stdio.h>

int main(){

    int min(int ,int);
    int max(int,int);
    int sum(int,int);

    int a=5,b=9;
    int flag=2;
    //指向函数的指针
    int (*p)(int,int);
    
    if(flag==1) p=min;
    if(flag==2) p=max;
    if(flag==3) p=sum;
    printf("%d",(*p)(a,b));
    return 0;
}

int min(int x,int y){return x<y?x:y;}
int max(int x,int y){return x>y?x:y;}
int sum(int x,int y){return x+y;}