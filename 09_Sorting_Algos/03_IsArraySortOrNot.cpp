#include<iostream>
using namespace std;
int main(){
    int arr[5] = {1,2,6,4,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<n-1;i++){
        if(arr[i]>arr[i+1]){
            cout<<"Array is not sorted"<<endl;
            return 0;
        }
    }
    cout<<"Array is sorted"<<endl;
    return 0;
}