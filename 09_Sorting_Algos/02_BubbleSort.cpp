#include<iostream>
using namespace std;
//Bubble sort
//Time complexity: O(n^2)
//Space complexity: O(1)
int main(){
    int arr[6] = {5,6,4,3,1,2};
    int n = sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    //bubble sort
    // for(int i=0;i<n-1;i++){
    //     for(int j = 0;j<n-i-1;j++){
    //         if(arr[j]>arr[j+1]){
    //             //swap(arr[j],arr[j+1]);
    //             int temp = arr[j];
    //             arr[j] = arr[j+1];
    //             arr[j+1] = temp;
    //         }
    //     }
    // }



    //optimized bubble sort
    for(int i=0;i<n-1;i++){
         bool flag = true;
         for(int j=0;j<n-1-i;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                flag = false;
            }
            if(flag == true){//swap didn't happen

                break;
            }
         }
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

}

//Bubble sort is a stable sorting algorithm that repeatedly steps through the list, compares adjacent elements and swaps them if they are in the wrong order. The pass through the list is repeated until the list is sorted. The algorithm gets its name because smaller elements "bubble" to the top of the list.
//Total no of swaps = n(n-1)/2

