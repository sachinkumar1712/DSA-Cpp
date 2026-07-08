#include<iostream>
using namespace std;
 class Node{//class declaration or Linked List Node
 public:
     int value;
     Node* next;
 
    Node(int value ){
       this->value = value;
       this->next = NULL;
    }
};
int main(){

    // Node a ;
    // a.value = 5;
    // Node b;
    // b.value = 10;
    // Node c;
    // c.value = 15;
    // Node d;
    // d.value = 20;
    Node a(5);
    Node b(10);
    Node c(15);
    Node d(20);

    // a.next = NULL;
    // b.next = NULL;
    // c.next = NULL;
    // d.next = NULL;

    a.next = &b;
    b.next = &c;
    c.next = &d;
    

    cout<<a.value<<endl;//accessing value of node a
    cout<<&a<<endl;//accessing address of node a
    cout<<a.next<<endl;//accessing address of next node of node a

    cout<<b.value<<endl;//10
    cout<<(*(a.next)).value<<endl;//10
    cout<<(a.next)->value<<endl;//10
    (a.next)->value = 100;//changing value of node b using node a
    cout<<b.value<<endl;//100

    cout<<c.value<<endl;//15
    cout<<(*(b.next)).value<<endl;//15
    cout<<(b.next)->value<<endl;//15
    cout<<(a.next)->next->value<<endl;//15
    
    cout<<d.value<<endl;//20
    cout<<(*(c.next)).value<<endl; //20
    cout<<(c.next)->value<<endl;//20
    cout<<(a.next)->next->next->value<<endl;//20
    cout<<(*((*((*(a.next)).next)).next)).value<<endl;//20
    cout<<(b.next)->next->value<<endl;//20
    cout<<endl;
    cout<<endl;


    Node temp = a;

    while(1){
        cout<<temp.value<<" ";
        if(temp.next == NULL){
            break;
        }
        temp = *(temp.next);
    }


}