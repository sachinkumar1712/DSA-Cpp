
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
vector<vector<int>> spiralMatrix(int m,int n,ListNode* head){
    vector<vector<int>> arr(m,vector<int>(n,-1));
    int minr=0,maxr=m-1;
    int minc=0,maxc=n-1;
    ListNode* temp=head;
    while(temp!=NULL){
        for(int j=minc;j<=maxc;j++){
            if(temp==NULL) break;
            arr[minr][j]=temp->val;
            temp=temp->next;
        }
        minr++;
        if(temp==NULL) break;
        for(int i=minr;i<=maxr;i++){
            if(temp==NULL) break;
            arr[i][maxc]=temp->val;
            temp=temp->next;
        }
        maxc--;
        if(temp==NULL) break;
        for(int j=maxc;j>=minc;j--){
            if(temp==NULL) break;
            arr[maxr][j]=temp->val;
            temp=temp->next;
        }
        maxr--;
        if(temp==NULL) break;
        for(int i=maxr;i>=minr;i--){
            if(temp==NULL) break;
            arr[i][minc]=temp->val;
            temp=temp->next;
        }
        minc++;
    }
    return arr;
}
int main(){
    ListNode* head=new ListNode(3);
    head->next=new ListNode(0);
    head->next->next=new ListNode(2);
    head->next->next->next=new ListNode(6);
    head->next->next->next->next=new ListNode(8);
    head->next->next->next->next->next=new ListNode(1);
    head->next->next->next->next->next->next=new ListNode(7);
    head->next->next->next->next->next->next->next=new ListNode(9);
    head->next->next->next->next->next->next->next->next=new ListNode(4);
    head->next->next->next->next->next->next->next->next->next=new ListNode(2);
    int m=3,n=5;
    vector<vector<int>> arr=spiralMatrix(m,n,head);
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
