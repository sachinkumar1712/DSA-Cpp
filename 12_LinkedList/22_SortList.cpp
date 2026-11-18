
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
ListNode* mergeTwoLists(ListNode* a,ListNode* b){
    ListNode* dummy=new ListNode(-1);
    ListNode* i=a;
    ListNode* j=b;
    ListNode* k=dummy;
    while(i!=NULL&&j!=NULL){
        if(i->val<j->val){
            k->next=i;
            i=i->next;
        }
        else{
            k->next=j;
            j=j->next;
        }
        k=k->next;
    }
    if(i==NULL) k->next=j;
    else k->next=i;
    return dummy->next;
}
ListNode* sortList(ListNode* head){
    if(head==NULL||head->next==NULL) return head;
    // Break the list into 2 halves
    ListNode* slow=head;
    ListNode* fast=head;
    while(fast->next!=NULL&&fast->next->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    ListNode* head2=slow->next;
    slow->next=NULL;
    head=sortList(head);
    head2=sortList(head2);
    return mergeTwoLists(head,head2);
}
void display(ListNode* head){
    while(head!=NULL){
        cout<<head->val<<" ";
        head=head->next;
    }
    cout<<endl;
}
int main(){
    ListNode* head=new ListNode(4);
    head->next=new ListNode(2);
    head->next->next=new ListNode(1);
    head->next->next->next=new ListNode(3);
    head->next->next->next->next=new ListNode(5);
    head=sortList(head);
    display(head);
    return 0;
}
