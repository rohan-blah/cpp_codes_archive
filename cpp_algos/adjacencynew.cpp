#include<iostream>
using namespace std;

int main()
{
    char choice;
    int v,flag=0,q,out=0,in=0;
    cout<<"enter the number of vertices: ";
    cin>>v;
    int ar[v][v];
    for(int i=0;i<v;i++)
    {
        for(int j=0;j<v;j++)
        {
            cout<<"\n How many edge from "<<(char)(97+i)<<" to "<<(char)(97+j)<<" - ";
            cin>>ar[i][j];
        }
    }

    cout<<"the adjancy matrix of graph is: \n";
    for(int k=0;k<v;k++)
    {
        cout<<endl;
        for(int l=0;l<v;l++)
        cout<<ar[k][l]<<" ";
    }


    for(int p=0;p<v;p++)
    {
        cout<<endl;
        for(int q=0;q<v;q++)
        {
            if((p!=q) && (p<q))
            {
                if(ar[p][q]!=1)
                {
                    flag=1;
                    break;
                }
            }
        }
    }

    if(flag==1)
    {
        cout<<"this is a not complete graph\n";
    }
    else
    {
        cout<<"this is a complete graph\n";
    }

     for(int i=0;i<v;i++)
    {
        for(int j=0;j<v;j++)
        {
            if(ar[i][j]>0)
            {
               out=out+ar[i][j];

            }
            if(ar[j][i]>0)
            {
                in=in+ar[j][i];
            }
        }
        cout<<"\n The degree of the vertex "<<(char)(97+i)<<" is:"<<out+in;
        out=0;
        in=0;

    }





}


