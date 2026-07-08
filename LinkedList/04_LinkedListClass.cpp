#include<iostream>
using namespace std;
class Node{//User defined data type
public:
    int value;
    Node* next;
    Node(int val){
        this->value=val;
        this->next=NULL;
    }
};
class LinkedList{//User defined data Structure
public:
    Node* head;
    Node* tail;
    int size;
    LinkedList(){
        head = tail = NULL;
        size = 0;
    }
    void insertAtTail(int val){
        Node* temp = new Node(val);
        if(size==0){
            head = tail = temp;
        }
        else{
            tail->next = temp;
            tail = temp;
        }
        size++;
    }
    void insertAtHead(int val){
        Node* temp = new Node(val);
        if(size==0){
            head = tail = temp;
        }else{
            temp->next = head;
            head = temp;
        }
        size++;
    }
    void insertAtIndex(int index,int value){
         if(index<0 || index>size){
            cout<<"Invalid Index"<<endl;
         }else if(index==0){
            insertAtHead(value);
         }else if(index==size){
            insertAtTail(value);
         }else{
            Node* t = new Node(value);
            Node* temp = head;
            for(int i=0;i<index-1;i++){
                temp = temp->next;
               
            }
            t->next = temp->next;
            temp->next = t;
            size++;

         }
    }

    int getAtIndex(int index){
        if(index<0||index>=size){
            cout<<"Invalid Index"<<endl;
            return -1;
        }else if(index==0){
            return head->value;
        }else if(index==size-1){
            return tail->value;
        }else{
            Node* temp = head;
            for(int i=1;i<=index;i++){
                temp = temp->next;
            }
            return temp->value;
        }
    }

   void deleteAtIndex(int index){
        if(index < 0 || index >= size){
            cout << "Invalid Index" << endl;
        }
        else if(index == 0){
             Node* temp = head;
             head = head->next;
             delete temp;
             size--;
             if(size == 0){
                tail = NULL;
            }
        }
        else if(index == size - 1){
             Node* temp = head;
             while(temp->next != tail){
                 temp = temp->next;
            }
            delete tail;
            tail = temp;
            tail->next = NULL;
            size--;
        }
        else{
            Node* temp = head;
            for(int i = 1; i <= index - 1; i++){
            temp = temp->next;
        }
        Node* t = temp->next;
        temp->next = t->next;
        delete t;
        size--;
        }
    }
    void display(){
        Node* temp = head;
        while(temp!=NULL){
            cout<<temp->value<<"->";
            temp = temp->next;
        }
        cout<<"NULL"<<endl;
    }

};
int main(){
    LinkedList ll ;//{NULL}
    ll.insertAtTail(10);//{10->NULL}
    ll.display();//10->NULL
    ll.insertAtTail(20);//{10->20->NULL}
    ll.display();//10->20->NULL
    ll.insertAtTail(30);//{10->20->30->NULL}
    ll.display();//10->20->30->NULL
    ll.insertAtTail(40);//{10->20->30->40->NULL} 
    ll.display();//10->20->30->40->NULL
    
    ll.insertAtHead(50);//{50->10->20->30->40->NULL}
    ll.display();//5->10->20->30->40->NULL
    ll.insertAtHead(60);//{60->50->10->20->30->40->NULL}
    ll.display();//60->50->10->20->30->40->NULL

    ll.insertAtIndex(2,100);//{60->50->100->10->20->30->40->NULL}
    ll.display();//60->50->100->10->20->30->40->NULL
    ll.insertAtIndex(0,200);//{200->60->50->100->10->20->30->40->NULL}
    ll.display();//200->60->50->100->10->20->30->40->NULL
    ll.insertAtIndex(8,300);//{200->60->50->100->10->20->30->40->300->NULL}
    ll.display();//200->60->50->100->10->20->30->40->300->NULL
    ll.insertAtIndex(10,400);//Invalid Index
    ll.display();//200->60->50->100->10->20->30->40->300->NULL

   cout << ll.getAtIndex(0) << endl;//200
   cout << ll.getAtIndex(3) << endl;//100
   cout << ll.getAtIndex(8) << endl;//300
   cout << ll.getAtIndex(10) << endl;//Invalid Index
   
   ll.deleteAtIndex(0);//{60->50->100->10->20->30->40->300->NULL}
   ll.display();//60->50->100->10->20->30->40->300->NULL
   ll.deleteAtIndex(7);//{60->50->100->10->20->30->40->NULL}
   ll.display();//60->50->100->10->20->30->40->NULL
   ll.deleteAtIndex(3);//{60->50->100->20->30->40->NULL}
   ll.display();//60->50->100->20->30->40->NULL
   ll.deleteAtIndex(10);//Invalid Index
   ll.display();//60->50->100->20->30->40->NULL


   cout<<"Size of Linked List: "<<ll.size<<endl;//4
}