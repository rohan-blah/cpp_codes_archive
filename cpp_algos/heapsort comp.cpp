#include<iostream>
#include<fstream>
#include<math.h>
#include<time.h>
using namespace std;

void maxHeapify(int[],int);
void buildMaxHeap(int[],int);
void heapSort(int[],int);
int heapSize;

int comparision=0;

bool already(int sizes[],int ele){
	for(int i=0;i<100;i++){
		if(sizes[i]==ele)
			return true;
	}
	return false;
}

int main(){
	int comparisions[100];
	int sizes[100];


	for(int i=0;i<100;i++){
		int size;
		do{
			size=rand();

		}while(size<30 || size>1000 || already(sizes,size));


		sizes[i]=size;

		int array[size];

		srand(time(NULL));

		for(int j=0;j<size;j++){
			array[j]=rand();
		}

		heapSort(array,size);
		comparisions[i]=comparision;
		comparision=0;
	}

	for(int i=0;i<100;i++){
		cout<<sizes[i]<<"\t"<<comparisions[i]<<endl;
	}cout<<endl;

	ofstream file("heapSort.dat");
	file<<"#x	y	xlogx"<<endl;
	for(int i=0;i<100;i++){
		file<<sizes[i]<<"\t"<<comparisions[i]<<"\t"<<sizes[i]*(int(log(sizes[i])))<<endl;
	}
	file.close();

}



void heapSort(int arr[],int size){
	buildMaxHeap(arr,size);
	for(int i=size-1;i>0;--i){
		arr[i]+=arr[0];
		arr[0]=arr[i]-arr[0];
		arr[i]=arr[i]-arr[0];
		heapSize--;
		maxHeapify(arr,0);
	}
}

void buildMaxHeap(int array[],int size){
	heapSize=size;
	for(int i=(size/2)-1;i>=0;--i){
		maxHeapify(array,i);
	}
}

void maxHeapify(int arr[],int i){
	int l=(2*i)+1;
	int r=(2*i)+2;
	int largest=i;
	if(l<heapSize && arr[i]<arr[l]){
		largest=l;
	}else{
		largest=i;
	}

	comparision++;

	if(r<heapSize && arr[r]>arr[largest]){
		largest=r;
	}

	comparision++;

	if(largest != i){
		arr[i]+=arr[largest];
		arr[largest]=arr[i]-arr[largest];
		arr[i]=arr[i]-arr[largest];
		maxHeapify(arr,largest);
	}

}
