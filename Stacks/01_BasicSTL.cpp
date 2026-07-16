#include<iostream>
#include<stack>
using namespace std;
int main(){
    stack<int>st;
    cout<<st.size()<<endl;
    st.push(10);
    // cout<<st.size()<<endl;
    st.push(20);
    st.push(30);
    st.push(40);
    cout<<st.size()<<endl;
    st.pop();
    cout<<st.size()<<endl;
    cout<<st.top()<<endl;
    // cout<<st;//error
    st.push(60);
    st.push(70);
    //printing in reverse order -> emptying the stack;
    // while(st.size()>0){
    //     cout<<st.top()<<" ";
    //     st.pop();
    // }


    //we will use the extra stack;
    stack<int>temp;
     while(st.size()>0){
        cout<<st.top()<<" ";
        temp.push(st.top());
        st.pop();
        
    }
    //putting element back from temp to stack;
    while(temp.size()>0){
       int x  = temp.top();
       st.push(temp.top());
       temp.pop();
    }
    cout<<endl<<st.top();
}