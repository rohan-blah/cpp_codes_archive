
#include <iostream>  
#include <string.h>  
#include <stack>
  
using namespace std; 
  
int evaluatePostfix(string exp)  
{  
     
    stack<char> st;
    int i;  
  
    for (i = 0; exp[i]; ++i)  
    {  
          
        if (isdigit(exp[i]))  
            st.push(exp[i] - '0');  
  
         
        else
        {  
            int val1 = st.top();st.pop();  
            int val2 = st.top();st.pop();  
            switch (exp[i])  
            {  
            case '+': st.push(val2 + val1); break;  
            case '-': st.push(val2 - val1); break;  
            case '*': st.push(val2 * val1); break;  
            case '/': st.push(val2/val1); break;  
            }  
        }  
    }  
    return st.top();  
}  
  

int main()  
{   
    string exp;
    cout<<"Enter the expression"<<endl;
    cin>>exp;
    cout<<"postfix evaluation: "<< evaluatePostfix(exp);  
    return 0;  
}  

