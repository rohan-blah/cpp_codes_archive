#include<iostream>
using namespace std;

string reverseString(string in,string out){
    if(in.length()==0)
        return "";
    else
    {
        char temp=in[0];
        in=in.substr(1);    
        return (reverseString(in,out)+temp);
    }
}

int main(){
    string in;
    string out="";
    cout<<"Enter a string: ";
    cin>>in;
    cout<<"The reversed string is: "<<reverseString(in,out)<<endl;
    return 0;
}