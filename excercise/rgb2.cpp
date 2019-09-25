#include <iostream>
using namespace std;

int main(){
	
	int r,g,b,n,signal,value,time=0;
	cin>>r>>g>>b>>n;
	while(n--){
		cin>>signal>>value;
		if(signal==0||1)
			cout<<(0||1);
			time+=value;
		if(signal==2)
			time+=value+r;
		if(signal==3)
			continue;
	}
	cout<<time;
	return 0;
}
