#include<iostream>
#include<stack>
using namespace std;

int main(){
    stack<int> st1;
    stack<int> st2;
    stack<int> st;

    string s;

    cout<<"Enter first number: "<<endl;
    cin>>s;
    int l1=s.length();
    for(int i=0;i<s.length();i++){
        char ch=s[i];
        st1.push(atoi(&ch));
    }

    cout<<"Enter second number: "<<endl;
    cin>>s;
    int l2=s.length();
    for(int i=0;i<s.length();i++){
        char ch=s[i];
        st2.push(atoi(&ch));
    }

    int m=max(l1,l2);
    int c=0;
    for(int i=0;i<m;i++){
        int a=0,b=0,s=0;
        if(!st1.empty())
        {
            a=st1.top();
            st1.pop();
        }
        if(!st2.empty())
        {
            b=st2.top();
            st2.pop();
        }
    s=a+b+c;
    st.push(s%10);
    c=s/10;
    }

    cout<<"Sum:  ";
    while(!st.empty()){
        cout<<st.top();
        st.pop();
    }
    return 0;
}
