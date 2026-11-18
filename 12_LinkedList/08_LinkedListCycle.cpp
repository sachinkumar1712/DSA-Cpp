
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
bool hasCycle(ListNode* head){
    ListNode* slow=head;
    ListNode* fast=head;
    while(fast!=NULL&&fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast) return true;
    }
    return false;
}
int main(){
    ListNode* head=new ListNode(1);
    head->next=new ListNode(2);
    head->next->next=new ListNode(3);
    head->next->next->next=new ListNode(4);

    // Create a cycle: 4 -> 2
    head->next->next->next->next=head->next;

    if(hasCycle(head)) cout<<"Cycle detected"<<endl;
    else cout<<"No cycle"<<endl;

    return 0;
}
