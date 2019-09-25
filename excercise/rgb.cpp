#include <iostream>
using namespace std;

int main(){
	
	int rgb[3];
	for(int i=0; i<3;i++){
		cin>>rgb[i];
	}
	
	int arrayLen=0;
	cin>>arrayLen;
	int array[arrayLen][2];
	
	
	for(int i=0; i<arrayLen;i++){
		for(int j=0;j<2;j++){
			cin>>array[i][j];
		}
	}
	
	int time=0;
	for(int i=0;i<arrayLen;i++){
		if(array[i][0]==2)
			time+=array[i][1]+rgb[0];
		if(array[i][0]==3)
			continue;
		else
			time+=array[i][1];
	}

	cout<<time<<endl;
	
	return 0;
}
