
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
ListNode* reverse(ListNode* head){
    ListNode* curr=head;
    ListNode* prev=NULL;
    while(curr!=NULL){
        ListNode* fwd=curr->next;
        curr->next=prev;
        prev=curr;
        curr=fwd;
    }
    return prev;
}
void reorderList(ListNode* head){
    if(head==NULL||head->next==NULL) return;
    // Reach the left middle and reverse the second half
    ListNode* slow=head;
    ListNode* fast=head;
    while(fast->next!=NULL&&fast->next->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    ListNode* a=head;
    ListNode* b=slow->next;
    slow->next=NULL;
    b=reverse(b);
    // Merge a and b alternatively
    ListNode* temp1=a;
    ListNode* temp2=b;
    while(temp2!=NULL){
        ListNode* fwd1=temp1->next;
        ListNode* fwd2=temp2->next;
        temp1->next=temp2;
        temp2->next=fwd1;
        temp1=fwd1;
        temp2=fwd2;
    }
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
    head->next=new ListNode(2);
    head->next->next=new ListNode(3);
    head->next->next->next=new ListNode(4);
    head->next->next->next->next=new ListNode(5);
    reorderList(head);
    display(head);
    return 0;
}
