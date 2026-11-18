
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
    if(head==NULL) return head;
    ListNode* i=head;
    ListNode* j=head;
    while(j!=NULL){
        if(i->val==j->val) j=j->next;
        else{
            i->next=j;
            i=j;
        }
    }
    if(i!=NULL) i->next=NULL;
    return head;
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
    head->next=new ListNode(1);
    head->next->next=new ListNode(2);
    head->next->next->next=new ListNode(3);
    head->next->next->next->next=new ListNode(3);
    head=deleteDuplicates(head);
    display(head);
    return 0;
}
