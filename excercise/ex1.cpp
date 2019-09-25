#include <iostream>
using namespace std;
int main() {
	int a,b,c;  //stand for three friends
	int count=0;  //the counts of lending methods
	for(a=1; a<=5; a++) { //a lends one of the five books
		for(b=1; b<=5; b++) { //b lends one of the five books
			if(a!=b) {
				for(c=1; c<=5; c++) {
					if(c!=a&&c!=b) {
						count++;
						cout<<count<<" "<<a<<" "<<b<<" "<<c<<"** ";
					}
					if(count%3==0) //view as a rule, any line has three lists
						cout<<endl;
				}

			}
		}

	}

}

