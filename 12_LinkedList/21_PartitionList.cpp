
#include<iostream>
using namespace std;
class ListNode{
public:
    int val;
    ListNode* next;
    ListNode(int val){
        this->val=val;
        next=NULL;
    }
};
ListNode* partition(ListNode* head,int x){
    ListNode* dummy1=new ListNode(-1);
    ListNode* dummy2=new ListNode(-1);
    ListNode* temp=head;
    ListNode* temp1=dummy1;
    ListNode* temp2=dummy2;
    while(temp!=NULL){
        ListNode* fwd=temp->next;
        if(temp->val<x){
            temp1->next=temp;
            temp1=temp;
        }
        else{
            temp2->next=temp;
            temp2=temp;
        }
        temp=fwd;
    }
    temp1->next=NULL;
    temp2->next=NULL;
    temp1->next=dummy2->next;
    return dummy1->next;
}
void display(ListNode* head){
    while(head!=NULL){
        cout<<head->val<<" ";
        head=head->next;
    }
    cout<<endl;
}
int main(){
    ListNode* head=new ListNode(1);
    head->next=new ListNode(4);
    head->next->next=new ListNode(3);
    head->next->next->next=new ListNode(2);
    head->next->next->next->next=new ListNode(5);
    head->next->next->next->next->next=new ListNode(2);
    int x=3;
    head=partition(head,x);
    display(head);
    return 0;
}
