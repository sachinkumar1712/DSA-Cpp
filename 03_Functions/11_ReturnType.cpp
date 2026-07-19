#include<iostream>
using namespace std;
int product(int a, int b){
    int ans = a*b;
    return ans;
}
int main(){
    int x = product(4,11);
    cout<<x;
}