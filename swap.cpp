#include <stdio.h>

void swap(int *p1,int *p2);
int main() {
	int *p1,*p2,*p,a=5,b=9;

	p1=&a;
	p2=&b;

	if(a<b) swap(p1,p2);
	printf("a=%d,b=%d\n",a,b);
	printf("*p1=%d,*p2=%d\n",*p1,*p2);
	return 0;
}
void swap(int *p1, int *p2) {
	int temp;
	temp=*p1;
	*p1=*p2;
	*p2=temp;
}
