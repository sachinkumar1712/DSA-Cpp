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

void display(Node* head){
    Node* temp = head;
    while(temp!= NULL){
        cout<<temp->value<<" ";
        temp = temp->next;
    }
    cout<<endl;
}
int size(Node* head){
    Node* temp = head;
    int count = 0;
    while(temp!=NULL){
        count++;
        temp = temp->next;
    }
    return count;
}
void displayRecursive(Node* head){
    if(head == NULL){
        cout<<endl;
        return;
    }
    cout<<head->value<<" ";
    displayRecursive(head->next);
}
void insertAtEnd(Node* head, int value){
    Node* temp = new Node(value);
    while(head->next!=NULL){
        head = head->next;
       
    }
     head->next = temp;
}

int main(){
    Node* a = new Node(10);
    Node* b = new Node(20);
    Node* c = new Node(30);
    Node* d = new Node(40);
    Node* e = new Node(50);

    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;
    display(a);//10 20 30 40 50
    insertAtEnd(a, 60);//10 20 30 40 50 60
    display(a);//10 20 30 40 50 60

    cout<<a->value<<endl;
    cout<<a->next->value<<endl;
    cout<<a->next->next->value<<endl;
    cout<<a->next->next->next->value<<endl;


    // Node* temp = a;
    // while(temp != NULL){
    //     cout<<temp->value<<" ";
    //     temp = temp->next;
    // } 

    // display(a);
    // displayRecursive(a);
    // cout<<size(a)<<endl;
}