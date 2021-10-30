#include<iostream>
#include<stdlib.h>
using namespace std;
int t;

void maxheapify(int a[],int n,int i)
{

   int largest=i;
	int l= 2*i+1;
	int r= 2*i+2;
	t++;
	if(l<n && a[l]>a[i])
	{

	largest = l;
	}

	if(r<n && a[r]>a[largest])
	{
		t++;
		largest = r;
	}

	if(largest!=i){
		t++;
		swap(a[i],a[largest]);
	   	maxheapify(a,n,largest);
	}

}

void bmax_heap(int a[],int n)
{

	for(int i=n/2-1;i>=0;i--)
	{
		maxheapify(a,n,i);
	}
}

void heap_sort(int a[],int n)
{

	bmax_heap(a,n);

	for(int i = n - 1 ;i>=0;i--)
	{

		swap(a[0],a[i]);
		maxheapify(a,i,0);
	}
}

void print(int a[],int n)
{

  for(int i=0;i<n;i++)
  {
  	cout<<a[i]<<" ";
  }
  cout<<endl<<"No. of comparisions = "<<t;
  cout<<endl<<endl<<endl<<endl;
  cout<<endl;
}

int main()
{
cout<<" SNO \t | \t length \t | \t Comparison";
for(int p=0;p<100;p++)
{
	t=0;

int k;
do{

	 k = rand();
}while(k<30 || k>1000);

	int a[k];
	for(int h=0;h<k;h++)
	{
		a[h]=rand();

	}

	int n= sizeof(a)/sizeof(a[0]);
//	cout<<"length of array is ="<<n<<endl;

	heap_sort(a,n);

//	cout<<"Sorted array is : ";
   // print(a,n);
 cout<< p<<" \t | \t"<< k<<" \t | \t"<< t;
 cout<<endl;
}
}
