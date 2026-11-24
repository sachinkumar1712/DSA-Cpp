#include<iostream>
#include<stack>
#include<vector>
using namespace std;
int calPoints(vector<string>& st){
      int ans = 0;
      stack<int> temp;
      for(string s: st){
            if(s=="C"){
                temp.pop();
            }else if(s=="D"){
                temp.push(2* (temp.top()));
            }else if(s=="+"){
                  int x = temp.top();
                  temp.pop();
                   int sum = x + temp.top();
                  temp.push(x);
                  temp.push(sum);
            }else{
                temp.push(stoi(s));
            }
        }

        while (!temp.empty()) {
            ans += temp.top();
            temp.pop();
        }

    return ans;
           
}

int main(){
    vector<string> arr = {"8","1","D","3","4","C","+","+"};

    cout<<calPoints(arr)<<endl;
}
