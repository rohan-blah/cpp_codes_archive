#include <iostream>
	using namespace std;

	void fibbonacci(int,int,int);

	int main(){
	   cout<<"Enter length of series : ";
	   int n;
	   cin>>n;
	   fibbonacci(n,0,1);
	}

	void fibbonacci(int size,int n1=0,int n2=1){
	   if(size<=0) return;
	   cout<<n1<<"  ";
	   int n3=n1+n2;
	   fibbonacci(size-1,n2,n3);
	}
