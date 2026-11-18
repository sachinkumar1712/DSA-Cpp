
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
ListNode* getIntersectionNode(ListNode* head1,ListNode* head2){
    int len1=length(head1);
    int len2=length(head2);
    ListNode* temp1=head1;
    ListNode* temp2=head2;
    if(len1>len2){
        for(int i=1;i<=len1-len2;i++){
            temp1=temp1->next;
        }
    }
    else{
        for(int i=1;i<=len2-len1;i++){
            temp2=temp2->next;
        }
    }
    while(temp1!=temp2){
        temp1=temp1->next;
        temp2=temp2->next;
    }
    return temp1;
}
int main(){
    ListNode* head1=new ListNode(4);
    head1->next=new ListNode(1);
    ListNode* head2=new ListNode(5);
    head2->next=new ListNode(6);
    head2->next->next=new ListNode(1);
    ListNode* common=new ListNode(8);
    common->next=new ListNode(4);
    common->next->next=new ListNode(5);
    head1->next->next=common;
    head2->next->next->next=common;
    ListNode* ans=getIntersectionNode(head1,head2);
    if(ans!=NULL) cout<<ans->val<<endl;
    else cout<<"No intersection"<<endl;
    return 0;
}
