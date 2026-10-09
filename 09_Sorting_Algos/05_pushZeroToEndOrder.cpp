#include<iostream>
using namespace std;
int main(){
    int arr[10] = {5,0,3,4,0,1,0,2,0,6};
    int n = sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    //push all the zeroes to the end of the array
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){
            if(arr[j]==0 ){
                swap(arr[j],arr[j+1]);
               
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}