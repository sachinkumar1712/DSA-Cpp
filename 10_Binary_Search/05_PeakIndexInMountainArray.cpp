
#include<iostream>
#include<vector>
using namespace std;
int peakIndexInMountainArray(vector<int>& arr){
    int n=arr.size();
    int lo=1,hi=n-2;
    while(lo<=hi){
        int mid=lo+(hi-lo)/2;
        if(arr[mid-1]<arr[mid]&&arr[mid]<arr[mid+1]) lo=mid+1;
        else if(arr[mid-1]>arr[mid]&&arr[mid]>arr[mid+1]) hi=mid-1;
        else return mid;
    }
    return -1;
}
int main(){
    vector<int> arr={0,2,5,3,1};
    cout<<peakIndexInMountainArray(arr)<<endl;
    return 0;
}
