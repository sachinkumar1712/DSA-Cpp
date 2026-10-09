//sort the string in decreasing order and less than 'X' in the string
#include<iostream>
#include<string>
using namespace std;
int main(){
    string s = "AZYZXBDXJK";
    int n = s.length();
    string str;
    for(int i=0;i<n;i++){
        if(s[i]>='X'){
            str.push_back(s[i]);
        }
    }
    // Sort the string in decreasing order
    for(int i=0;i<str.length();i++){
        for(int j=i+1;j<str.length();j++){
            if(str[i]<str[j]){
                swap(str[i],str[j]);
            }
        }
    }
    cout<<str<<endl;
}