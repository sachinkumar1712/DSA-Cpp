
#include<iostream>
#include<vector>
using namespace std;
vector<int> searchRange(vector<int>& arr,int target){
    int n=arr.size();
    vector<int> ans(2,-1);
    // First Occurence
    int lo=0,hi=n-1;
    while(lo<=hi){ // O(logn)
        int mid=(lo+hi)/2;
        if(arr[mid]>target) hi=mid-1;
        else if(arr[mid]<target) lo=mid+1;
        else{
            ans[0]=mid;
            hi=mid-1;
        }
    }
    // Last Occurence
    lo=0;
    hi=n-1;
    while(lo<=hi){ // O(logn)
        int mid=(lo+hi)/2;
        if(arr[mid]>target) hi=mid-1;
        else if(arr[mid]<target) lo=mid+1;
        else{
            ans[1]=mid;
            lo=mid+1;
        }
    }
    return ans;
}
int main(){
    vector<int> arr={5,7,7,8,8,10};
    int target=8;
    vector<int> ans=searchRange(arr,target);
    cout<<ans[0]<<" "<<ans[1]<<endl;
    return 0;
}
