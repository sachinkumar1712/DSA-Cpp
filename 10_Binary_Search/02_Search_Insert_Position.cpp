
#include<iostream>
#include<vector>
using namespace std;
int searchInsert(vector<int>& arr,int target){
    int n=arr.size();
    int lo=0,hi=n-1;
    while(lo<=hi){ // O(logn)
        int mid=(lo+hi)/2;
        if(arr[mid]>target) hi=mid-1;
        else if(arr[mid]<target) lo=mid+1;
        else return mid;
    }
    return lo;
}
int main(){
    vector<int> arr={1,3,5,6};
    int target=2;
    cout<<searchInsert(arr,target)<<endl;
    return 0;
}
