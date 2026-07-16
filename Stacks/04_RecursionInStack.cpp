#include<iostream>
#include<stack>
using namespace std;
void displayRevRec(stack<int>& st){
    if(st.size()==0) return;
   int x = st.top();
   cout<<x<<" ";
    st.pop();
    displayRevRec(st);
    st.push(x);
}
void displayRec(stack<int>& st){
    if(st.size()==0) return;
    int x = st.top();
    st.pop();
    displayRec(st);
    cout<<x<<" ";
    st.push(x);


}
void pushAtBottomRec(stack<int>& st,int value){
    if(st.size()==0){
        st.push(value);
        return;

    }
    int x = st.top();
    st.pop();
    pushAtBottomRec(st,value);
    st.push(x);

}
void reverse(stack<int>& st){
    if(st.size()==0) return;
    int x = st.top();
    st.pop();
    reverse(st);
    pushAtBottomRec(st,x);

}
int main(){
    stack<int>st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    displayRevRec(st);
    cout<<endl;
    displayRec(st);
    cout<<endl;
    pushAtBottomRec(st,-10);
    cout<<endl;
    displayRec(st);
    cout<<endl;
    reverse(st);
    displayRec(st);
}