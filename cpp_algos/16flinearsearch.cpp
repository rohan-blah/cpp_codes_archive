#include<iostream>
using namespace std;
int main(){
  cout<<"Enter size of array"<<endl;
  int n;
  cin>>n;
  cout<<"Enter array of integers"<<endl;
  int ar[n];
  for(int i=0;i<n;i++){
    cin>>ar[i];
  }
  int key;
  cout<<"Enter key to search for"<<endl;
  cin>>key;
  bool flag=false;
  for(int i=0;i<n;i++){
    if(ar[i]==key){
      cout<<"Found "<<key<<" at index "<<i<<endl;
      flag=true;
    }
  }
  if(!flag)
    cout<<key<<" not found"<<endl;
  return 0;
}
