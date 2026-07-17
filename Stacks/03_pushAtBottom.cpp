#include<iostream>
#include<stack>
using namespace std;
void print(stack<int>st){
     stack<int>temp;
     while(st.size()>0){
        temp.push(st.top());
        st.pop();
        
    }
    //putting element back from temp to stack;
    while(temp.size()>0){
        cout<<temp.top()<<" ";
       int x  = temp.top();
       st.push(temp.top());
       temp.pop();
    }
    cout<<endl;
}
void pushAtBottom(stack<int>&st,int value){
    stack<int>temp;
    while(st.size()>0){
        temp.push(st.top());
        st.pop();  
    }
    st.push(value);
     while(temp.size()>0){
       st.push(temp.top());
       temp.pop();
    }  
    
}
void pushAtAnyIndex(stack<int>& st,int index,int value){
    stack<int>temp;
    while(st.size()>index){
        temp.push(st.top());
        st.pop();  
    }
    st.push(value);
     while(temp.size()>0){
       st.push(temp.top());
       temp.pop();
    }  
}
int main(){
    stack<int>st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    print(st);
    pushAtBottom(st,80);
    print(st);
    pushAtAnyIndex(st,2,90);
    print(st); 

}
