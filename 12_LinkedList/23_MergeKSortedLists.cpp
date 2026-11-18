
#include<iostream>
#include<vector>
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
ListNode* merge(ListNode* a,ListNode* b){ // TC = O(m+n)
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
ListNode* mergeKLists(vector<ListNode*>& arr){
    if(arr.size()==0) return NULL;
    vector<ListNode*> temp;
    while(arr.size()+temp.size()>1){
        while(arr.size()>1){
            ListNode* a=arr[arr.size()-1];
            arr.pop_back();
            ListNode* b=arr[arr.size()-1];
            arr.pop_back();
            ListNode* c=merge(a,b);
            temp.push_back(c);
        }
        while(temp.size()>1){
            ListNode* a=temp[temp.size()-1];
            temp.pop_back();
            ListNode* b=temp[temp.size()-1];
            temp.pop_back();
            ListNode* c=merge(a,b);
            arr.push_back(c);
        }
        if(arr.size()==1&&temp.size()==1){
            temp.push_back(arr[0]);
            arr.pop_back();
        }
    }
    return (arr.size()!=0)?arr[0]:temp[0];
}
void display(ListNode* head){
    while(head!=NULL){
        cout<<head->val<<" ";
        head=head->next;
    }
    cout<<endl;
}
int main(){
    vector<ListNode*> arr(3);
    arr[0]=new ListNode(1);
    arr[0]->next=new ListNode(4);
    arr[0]->next->next=new ListNode(5);
    arr[1]=new ListNode(1);
    arr[1]->next=new ListNode(3);
    arr[1]->next->next=new ListNode(4);
    arr[2]=new ListNode(2);
    arr[2]->next=new ListNode(6);
    ListNode* ans=mergeKLists(arr);
    display(ans);
    return 0;
}
