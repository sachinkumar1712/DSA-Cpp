
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
ListNode* swapPairs(ListNode* head){
    if(head==NULL||head->next==NULL) return head;
    ListNode* a=head;
    ListNode* prev=NULL;
    while(a!=NULL){
        ListNode* b=a->next;
        if(b==NULL){
            prev->next=a;
            break;
        }
        ListNode* fwd=b->next;
        b->next=a;
        if(prev!=NULL) prev->next=b;
        else head=b;
        prev=a;
        a->next=NULL;
        a=fwd;
    }
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
    head->next=new ListNode(2);
    head->next->next=new ListNode(3);
    head->next->next->next=new ListNode(4);
    head->next->next->next->next=new ListNode(5);
    head=swapPairs(head);
    display(head);
    return 0;
}
