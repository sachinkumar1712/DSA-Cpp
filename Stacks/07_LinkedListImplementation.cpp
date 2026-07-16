#include<iostream>
using namespace std;
class Node{
    public:
    int value;
    Node* next;
    Node(int value){
       this->value = value;
       this->next = NULL;
    }
};
class Stack{
    public:
    Node* head;
    int size;
    Stack(){
        head = NULL;
        size = 0;
    }
    void push(int value){
        Node* temp = new Node(value);
        temp->next = head;
        head = temp;
        size++; 
    }
    void pop(){
        if(head==NULL) {
            cout<<"Stack is empty."<<endl;
            return;
        }
        head = head->next;
        size--;
    }
    int top(){
        if(head==NULL){
            cout<<"Stack is empty."<<endl;
            return -1;
        }
        return head->value;
    }
    void print(Node* temp){
       if(temp==NULL) return;
       print(temp->next);
       cout<<temp->value<<" "; 
    }
    void display(){
       Node* temp = head;
       print(temp);
       cout<<endl;
    }
};
int main(){
      Stack st;
     cout<<st.top()<<endl;
     st.push(10);
     st.push(20);
     st.push(30);
     st.push(40);
    st.pop();
    cout<<st.top()<<endl;
    st.push(60);
    st.push(70);
    cout<<st.top()<<endl;
    st.display();
}