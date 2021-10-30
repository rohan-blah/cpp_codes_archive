#include<iostream>
using namespace std;

int main(){
	cout<<"Enter choise: "<<endl;
	cout<<"1.Digonal matrix"<<endl;
	cout<<"2.Lower Triangular matrix"<<endl;
	cout<<"3.Upper triangular matrix"<<endl;
	cout<<"4.Symmetric matrix"<<endl;
	int ch;
	cin>>ch;
	cout<<"Enter matrix size: ";
	int n;
	cin>>n;
	if(ch==1){
		
		int temp[n][n];
		int sparse[n];
		cout<<"Enter matrix elements"<<endl;
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				cin>>temp[i][j];
		cout<<"Digonal Matrix"<<endl;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cout<<temp[i][j]<<" ";
				if(temp[i][j]!=0)
					sparse[i]=temp[i][j];
			}
			cout<<endl;
		}
		cout<<"Sparse representation:"<<endl;
		for(int i=0;i<n;i++)
			cout<<sparse[i]<<" ";
		cout<<endl;
	}
	if(ch==2){
		int temp[n][n];
		int sparse[(n*(n+1))/2];
		cout<<"Enter matrix elements"<<endl;
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				cin>>temp[i][j];
		cout<<"Lower Triangular Matrix"<<endl;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cout<<temp[i][j]<<" ";
				if(temp[i][j]!=0)
					sparse[((i*(i+1))/2)+j]=temp[i][j];
			}
			cout<<endl;
		}
		cout<<"Sparse representation:"<<endl;
		for(int i=0;i<((n*(n+1))/2);i++)
			cout<<sparse[i]<<" ";
		cout<<endl;
	}
	if(ch==3){
		int temp[n][n];
		int sparse[(n*(n+1))/2];
		cout<<"Enter matrix elements"<<endl;
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				cin>>temp[i][j];
		cout<<"Upper Triangular Matrix"<<endl;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cout<<temp[i][j]<<" ";
				if(temp[i][j]!=0)
					sparse[(n*i)-((i-1)*i)/2+j-i]=temp[i][j];
			}
			cout<<endl;
		}
		cout<<"Sparse representation:"<<endl;
		for(int i=0;i<((n*(n+1))/2);i++)
			cout<<sparse[i]<<" ";
		cout<<endl;
	}
	if(ch==4){
		int temp[n][n];
		int sparse[(n*(n+1))/2];
		cout<<"Enter matrix elements"<<endl;
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				cin>>temp[i][j];
		cout<<"Symmetrix Matrix"<<endl;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cout<<temp[i][j]<<" ";
				if(temp[i][j]!=0)
					sparse[((i*(i+1))/2)+j]=temp[i][j];
			}
			cout<<endl;
		}
		cout<<"Sparse representation:"<<endl;
		for(int i=0;i<((n*(n+1))/2);i++)
			cout<<sparse[i]<<" ";
		cout<<endl;
	}
	return 0;
}
