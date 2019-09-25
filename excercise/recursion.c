#include <stdio.h>

int main(){
    int f(int x);
    printf("%d",f(3));
    return 0;
}

int f(int x){
    if (x==1) {
        return 1;
    }else
    {
        //递推式 an=f(an-1)
        return x*f(x-1);
    }
}