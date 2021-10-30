#include<iostream>
using namespace std;

void merge(int ar[],int l,int m,int r){
    int i,j,k;
    int sl=m-l+1;
    int sr=r-m;
    int L[sl];
    int R[sr];
    for(i=0;i<sl;i++)
        L[i]=ar[l+i];
    for(j=0;j<sr;j++)
        R[j]=ar[m+1+j];
    i=j=0;
    k=l;
    while(i<sl&&j<sr){
        if(L[i]<=R[j])
            ar[k++]=L[i++];
        else 
            ar[k++]=R[j++];
    }
    while(i<sl)
        ar[k++]=L[i++];
    while(j<sr)
        ar[k++]=R[j++];
}

void mergesort(int ar[],int l,int r){
    if(l<r){
        int m=l+(r-l)/2;
        mergesort(ar,l,m);
        mergesort(ar,m+1,r);
        merge(ar,l,m,r);
    }
}

int main(){
    cout<<"Enter the size of array"<<endl;
	int n;
	cin>>n;
	int ar[n];
	cout<<"Enter array elements"<<endl;
	for(int i=0;i<n;i++){
		cin>>ar[i];
	}
	cout<<"Elements before sorting"<<endl;
	for(int i:ar)
		cout<<i<<" ";
	mergesort(ar,0,n-1);
	cout<<endl<<"Elements after sorting"<<endl;
	for(int i:ar)
		cout<<i<<" ";
    return 0;
}