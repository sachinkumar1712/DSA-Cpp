
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
bool isPalindrome(ListNode* head){
    if(head==NULL||head->next==NULL) return true;
    // Reach the left middle
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
    ListNode* t1=a;
    ListNode* t2=b;
    bool flag=true;
    while(t2!=NULL){
        if(t1->val!=t2->val){
            flag=false;
            break;
        }
        t1=t1->next;
        t2=t2->next;
    }
    slow->next=reverse(b);
    return flag;
}
int main(){
    ListNode* head=new ListNode(1);
    head->next=new ListNode(2);
    head->next->next=new ListNode(2);
    head->next->next->next=new ListNode(1);
    if(isPalindrome(head)) cout<<"Palindrome"<<endl;
    else cout<<"Not Palindrome"<<endl;
    return 0;
}
