#include <stdio.h>

int main(){

    float *search(float (*arr)[4],int k);
    
    float score[][4]={{23,6,79},{34,66,89},{79,59,90},{20,67,90}};
    int k=3;
    float *p;
    p=search(score,k);
    //print
    int n=3;
    while(n--){
        printf("%f ",*(p++));
    }
    
    return 0;
}

float *search(float (*arr)[4],int k){

    return *(arr+k);
}