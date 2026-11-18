
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
ListNode* deleteDuplicates(ListNode* head){
    ListNode* dummy=new ListNode(-1);
    ListNode* temp1=head;
    ListNode* temp2=dummy;
    while(temp1!=NULL){
        ListNode* x=temp1->next;
        if(x!=NULL&&temp1->val==x->val){
            while(x!=NULL&&x->val==temp1->val) x=x->next;
            temp1=x;
        }
        else{
            temp2->next=temp1;
            temp2=temp1;
            temp1=temp1->next;
        }
    }
    temp2->next=NULL;
    return dummy->next;
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
    head->next->next->next=new ListNode(3);
    head->next->next->next->next=new ListNode(4);
    head->next->next->next->next->next=new ListNode(4);
    head->next->next->next->next->next->next=new ListNode(5);
    head=deleteDuplicates(head);
    display(head);
    return 0;
}
