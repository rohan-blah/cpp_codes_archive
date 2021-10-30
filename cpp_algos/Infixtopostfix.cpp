/*
A+(B*C-(D/E-F)*G)*H
*/

#include<iostream>
#include<string>
using namespace std;

void push(string &s,int &top,char ch)
{
    s[++top]=ch;
}
char pop(string &s,int &top)
{
    top--;
    return s[top+1];
}
int prec(char ch)
{
    if(ch=='+'||ch=='-')
    return 10;
    else if(ch=='*'||ch=='/')
    return 20;
    else if(ch=='^')
    return 30;
    else
    return 0;
}

int main()
{
    string input,output="                        ",stack="                       ";
    cout<<"Enter Infix Expression:"<<endl;
    cin>>input;
    int ins=input.size()-1,outs=-1,sts=-1;

    for(int i=0;i<=ins;i++)
    {
        if( (input[i]>='A'&&input[i]<='Z'))
            push(output,outs,input[i]);

        else if (input[i]=='(')
            push(stack,sts,input[i]);

        else if(input[i]==')')
        {
            while(stack[sts]!='(')
                    push(output,outs,pop(stack,sts));
            sts--;
        }

        else if(input[i]=='+'|| input[i]=='-'|| input[i]=='*' || input[i]=='/')
        {
            while(prec(stack[sts])>=prec(input[i]))
            push(output,outs,pop(stack,sts));

        push(stack,sts,input[i]);
        }
    }

    while(sts!=-1)
    push(output,outs,pop(stack,sts));

    cout<<"Postfix Expression:"<<endl;
    cout<<output;
    return 0;
}
