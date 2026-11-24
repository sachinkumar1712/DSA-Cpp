#include<iostream>
using namespace std;
class Node{ // user defined data structure
public:
    int val;
    Node* next;
    Node(int val){
        this->val = val;
        next = NULL;
    }
};
class MyStack{ // user defined data structure
private:
    Node* head;
    Node* tail;
    int length;
public:
    MyStack(){
        head = tail = NULL;
        length = 0;
    }
    void push(int val){
        Node* n = new Node(val);
        n->next = head;
        head = n;
        length++;
    }
    void pop(){
        if(length == 0){
            cout<<"Stack is Empty!"<<endl;
            return;
        }
        Node* toBeDeleted = head;
        head = head->next;
        delete toBeDeleted;
        length--;
    }
    int get(){
        if(length == 0){
            cout<<"Stack is Empty!"<<endl;
            return -1;
        }
        return head->val;
    }
    int size(){
        return length;
    }
    void display(){ // Top to Bottom
        Node* temp = head;
        while(temp){
            cout<<temp->val<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
};
int main(){
    MyStack st;
    st.push(10); // add at top
    st.push(20);
    st.push(30);
    st.pop(); // remove the top
    st.push(40);
    st.display();
}