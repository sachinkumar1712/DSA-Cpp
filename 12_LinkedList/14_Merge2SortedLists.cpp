
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
void display(ListNode* head){
    while(head!=NULL){
        cout<<head->val<<" ";
        head=head->next;
    }
    cout<<endl;
}
int main(){
    ListNode* a=new ListNode(1);
    a->next=new ListNode(3);
    a->next->next=new ListNode(5);
    ListNode* b=new ListNode(2);
    b->next=new ListNode(4);
    b->next->next=new ListNode(6);
    ListNode* ans=mergeTwoLists(a,b);
    display(ans);
    return 0;
}
