#include<iostream>
using namespace std;

int main()
{
    int x[4],y[4],Bicond[4],XNOR[4],Negx[4],Negy[4],NAND[4],NOR[4];
    char ch;
    do
    {
        for(int i=0;i<4;i++)
        {
            cout<<"Enter the"<<" "<<(i+1)<<" "<<"value of x and y"<<endl;
            cin>>x[i]>>y[i];
            Bicond[i]=((!x[i]|y[i])&(!y[i]|x[i]));
            XNOR[i]=((!x[i]&!y[i])|(x[i]&y[i]));
            Negx[i]=!x[i];
            Negy[i]=!y[i];
            NAND[i]=!(x[i]&y[i]);
            NOR[i]=!(x[i]+y[i]);

        }

        cout<<"x |y  |XNOR |Bicond    |Negx |Negy |NAND |NOR|"<<endl;
        for(int i=0;i<4;i++)
        {
           cout<<x[i]<<" | "<<y[i]<<" | "<<XNOR[i]<<"   |"<<Bicond[i]<<"         |"<<Negx[i]<<"    |"<<Negy[i]<<"    |"<<NAND[i]<<"    |"<<NOR[i]<<"  |"<<endl;

        }
        cout<<"do you want to continue(y/n)\n";
        cin>>ch;
    }while(ch=='y');

    return 0;
    }
