#include <iostream>
using namespace std;

int main(){
	
	int r,g,y,n;
	cin>>r>>y>>g>>n;
	int signal,value,time;
	
	while(n--){
		cin>>signal>>value;
		int period=(value-time)%(r+g+y);
		if(signal==0)
			time+=value;
		//red
		if(signal==1)
			if(period > 0)
				time+=(value-time);
			else if(period > - (g) )
				continue;
			else if(period>-(g+y))
				time+=r+(-period)-g;
		//green
		if(signal==3)
			if(period>0)
				continue;
			else if(period>-(y))
				time+=r+(-period);
			else if(period>-(y+r))
				time+=(r-((-period)-y));
		//yello
		if(signal==2)
			if(period>0)
				time+=r+period;
			else if(period>-(r))
				time+=(r-(-period));
			else if(period>-(r+g))
				continue;
				
	}
	cout<<time;
	return 0;
}
