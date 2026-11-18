
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
int length(ListNode* head){
    int len=0;
    ListNode* temp=head;
    while(temp!=NULL){
        len++;
        temp=temp->next;
    }
    return len;
}
ListNode* rotateRight(ListNode* head,int k){
    if(head==NULL||head->next==NULL) return head;
    int n=length(head);
    k=k%n;
    if(k==0) return head;
    ListNode* a=head;
    ListNode* b=head;
    ListNode* c=head;
    ListNode* temp=head;
    for(int i=1;i<=n;i++){
        if(i==n-k) a=temp;
        if(i==n-k+1) b=temp;
        if(i==n) c=temp;
        temp=temp->next;
    }
    a->next=NULL;
    c->next=head;
    return b;
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
    int k=2;
    head=rotateRight(head,k);
    display(head);
    return 0;
}
