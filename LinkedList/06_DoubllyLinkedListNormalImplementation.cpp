#include<iostream>
using namespace std;
class Node{
public:
    int value;
    Node* next;
    Node* prev;
    Node(int value){
        this->value = value;
        this->next = NULL;
        this->prev = NULL;
    }
};
// void display(Node* head){
//     while(head!=NULL){
//         cout<<head->value<<"->";
//         head = head->next;
//     }
//     cout<<"NULL"<<endl;
// }
void displayRec(Node* head){
    if(head==NULL) return;
    cout<<head->value<<" ";
    displayRec(head->next);
    
}
void displayRecRev(Node* head){
    if(head==NULL) return;
    displayRecRev(head->next);
    cout<<head->value<<" ";
   
}
void display(Node* tail){
    while(tail!=NULL){
        cout<<tail->value<<" ";
        tail = tail->prev;
    }
    cout<<endl;
}
int main(){
    Node* a = new Node(10);
    Node* b = new Node(20);
    Node* c = new Node(30);
    Node* d = new Node(40);
    Node* e = new Node(50);
    a->next = b;
    b->prev = a;
    b->next = c;
    c->prev = b;
    c->next = d;
    d->prev = c;
    d->next = e;
    e->prev = d;

    // display(a);//10->20->30->40->50->NULL
    displayRec(a);//10->20->30->40->50->NULL
    cout<<endl;
    displayRecRev(a);//50 40 30 20 10 %  
    cout<<endl;  
    display(e);    

}