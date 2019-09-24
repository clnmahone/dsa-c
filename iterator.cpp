#include <iostream>
#include <functional>
#include <iterator>
#include <algorithm>
using namespace std;

double f(double x){
	return x*x;
}

int main(){
	transform(istream_iterator<double>(cin),istream_iterator<double>(),ostream_iterator<double>(cout,"\t"),f);
	cout<<endl;
	return 0;
}