
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
ListNode* detectCycle(ListNode* head){
    ListNode* slow=head;
    ListNode* fast=head;
    while(fast!=NULL&&fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast) break;
    }
    if(fast==NULL||fast->next==NULL) return NULL;
    ListNode* temp=head;
    while(temp!=slow){
        slow=slow->next;
        temp=temp->next;
    }
    return slow;
}
int main(){
    ListNode* head=new ListNode(1);
    head->next=new ListNode(2);
    head->next->next=new ListNode(3);
    head->next->next->next=new ListNode(4);
    head->next->next->next->next=new ListNode(5);

    // Create cycle: 5 -> 3
    head->next->next->next->next->next=head->next->next;

    ListNode* ans=detectCycle(head);
    if(ans!=NULL) cout<<"Cycle starts at: "<<ans->val<<endl;
    else cout<<"No cycle"<<endl;
    return 0;
}
