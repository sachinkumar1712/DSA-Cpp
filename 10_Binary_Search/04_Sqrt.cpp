
#include<iostream>
using namespace std;
int mySqrt(int n){ // O(logn)
    if(n==0) return 0;
    int lo=1,hi=n;
    while(lo<=hi){
        int mid=lo+(hi-lo)/2;
        if(mid>n/mid) hi=mid-1;
        else if(mid<n/mid) lo=mid+1;
        else return mid;
    }
    return hi;
}
int main(){
    int n=8;
    cout<<mySqrt(n)<<endl;
    return 0;
}
