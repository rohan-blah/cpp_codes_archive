#include <iostream>
#include <cstdlib>
using namespace std;

int getMax(int arr[], int n){
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}

// count sort of arr[]
void countSort(int arr[], int n, int exp){
    int output[n];
    int i, count[10] = {0};
    for (i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (i = n - 1; i >= 0; i--)
    {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
    for (i = 0; i < n; i++)
        arr[i] = output[i];
}

void radixsort(int arr[], int n){
    int m = getMax(arr, n);
    for (int exp = 1; m / exp > 0; exp *= 10)
    countSort(arr, n, exp);
}

int main(){

    int k;
    do{
	   k = rand();
    }while(k>20);

	int a[k];
	for(int h=0;h<k;h++){
		a[h]=rand()%1000;
	}

	cout<<"LENGTH OF ARRAY IS = "<<k;

    cout<<"\nARRAY BEFORE SORTING(RADIX SORT)\n";

    for (int i = 0; i < k; i++){
        cout << a[i] << " ";
    }cout<<endl;



    radixsort(a, k);


    cout<<"\nARRAY AFTER SORTING(RADIX SORT)\n";

    for (int i = 0; i < k; i++){
		cout << a[i] << " ";
    }cout<<endl;

}
