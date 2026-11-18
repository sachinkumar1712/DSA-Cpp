
#include<iostream>
using namespace std;
class Node{
public:
    int data;
    Node* next;
    Node* prev;
    Node(int data){
        this->data=data;
        next=NULL;
        prev=NULL;
    }
};
Node* reverse(Node* head){
    Node* curr=head;
    Node* back=NULL;
    while(curr!=NULL){
        Node* fwd=curr->next;
        curr->next=back;
        curr->prev=fwd;
        back=curr;
        curr=fwd;
    }
    return back;
}
void display(Node* head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}
int main(){
    Node* head=new Node(1);
    Node* second=new Node(2);
    Node* third=new Node(3);
    Node* fourth=new Node(4);
    head->next=second;
    second->prev=head;
    second->next=third;
    third->prev=second;
    third->next=fourth;
    fourth->prev=third;
    head=reverse(head);
    display(head);
    return 0;
}
