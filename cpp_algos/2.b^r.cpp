#include<iostream>
using namespace std;
int fun(int b,int r){
if(r==1)
	return b;
else
	return b*fun(b,r-1);
}

int main(){
int b,r;
cout<<"Enter the values of b and r to calculate b^r"<<endl;
cin>>b>>r;
cout<<b<<"^"<<r<<"="<<fun(b,r);
return 0;
}
