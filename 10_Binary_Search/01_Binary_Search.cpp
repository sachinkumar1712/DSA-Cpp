#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> arr={1,3,5,7,9,11};
    int target=7;
    int n=arr.size();
    int lo=0,hi=n-1;
    while(lo<=hi){
        int mid=(lo+hi)/2;
        if(arr[mid]>target) hi=mid-1;
        else if(arr[mid]<target) lo=mid+1;
        else{
            cout<<mid<<endl;
            return 0;
        }
    }
    cout<<-1<<endl;
    return 0;
}