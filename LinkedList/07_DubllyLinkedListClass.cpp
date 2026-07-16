#include<iostream>
using namespace std;

class Node{
public:
    int value;
    Node* next;
    Node* prev;

    Node(int value){
        this->value = value;
        this->next = NULL;
        this->prev = NULL;
    }
};

class DLL{
public:
    Node* head;
    Node* tail;
    int size;

    DLL(){
        head = tail = NULL;
        size = 0;
    }

    void insertAtTail(int value){
        Node* temp = new Node(value);

        if(size==0){
            head = tail = temp;      // Fixed
        }
        else{
            tail->next = temp;
            temp->prev = tail;
            tail = temp;
        }
        size++;
    }

    void insertAtHead(int value){
        Node* temp = new Node(value);

        if(size==0){
            head = tail = temp;      // Fixed
        }
        else{
            temp->next = head;
            head->prev = temp;
            head = temp;
        }
        size++;
    }

    void insertAtIdx(int idx,int value){

        if(idx<0 || idx>size){
            cout<<"Invalid Index"<<endl;
        }

        else if(idx==0){

            Node* temp = new Node(value);

            if(size==0){
                head = tail = temp;      // Fixed
            }
            else{
                temp->next = head;       // Fixed
                head->prev = temp;
                head = temp;
            }
            size++;
        }

        else if(idx==size){

            Node* temp = new Node(value);

            if(size==0){
                head = tail = temp;      // Fixed
            }
            else{
                tail->next = temp;       // Fixed
                temp->prev = tail;
                tail = temp;
            }
            size++;
        }

        else{

            Node* t = new Node(value);
            Node* temp = head;

            for(int i=1;i<idx;i++){
                temp = temp->next;
            }

            t->next = temp->next;
            temp->next = t;
            t->prev = temp;
            t->next->prev = t;

            size++;
        }
    }

    
   void deleteAtHead(){
      if(size==0){
         cout<<"List is Empty!";
         return;
      }
      head = head->next;
      if(head!=NULL){
         head->prev = NULL;
      }
      if(head==NULL){
         tail=NULL;
      }
      size--;
   }
   void deleteAtTail(){
      if(size==0){
         cout<<"List is Empty!";
         return;
      }
      else if(size==1){
         deleteAtHead();
         return;
      }
      Node* temp = tail->prev;
      temp->next = NULL;
      tail = temp;
      size--;
   }
   void deleteAtIdx(int idx){
         if(size==0){
            cout<<"List is Empty";
            return;
         }else if(idx<0||idx>=size){
             cout<<"Invalid Index";
             return;
         }
         else if(idx == 0) return deleteAtHead();
         else if(idx==size-1) return deleteAtTail();
         else{
            Node* temp = head;
            for(int i=1;i<=idx-1;i++){
               temp = temp->next;
            }
            temp->next = temp->next->next;
            temp->next->prev = temp;
            size--;
         }
   }
    
   int getAtIdx(int idx){
       if(idx<0||idx>=size){
         cout<<"Invalid Index";
         return -1;
       }
       else if(idx==0) return head->value;
       else if(idx==size-1) return tail->value;
       else{
         if(idx<size/2){
            Node* temp = head;
            for(int i=0;i<idx;i++){
               temp = temp->next;
            }
            return temp->value;
         }else{
             Node* temp = head;
             for(int i=1;i<size-idx;i++){
             temp = temp->prev;
            }
            return temp->value;
         }
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

    DLL list;

    list.insertAtTail(10);
    list.insertAtTail(20);
    list.insertAtTail(30);
    list.display();

    list.insertAtTail(40);
    list.display();

    list.insertAtHead(50);
    list.insertAtHead(70);
    list.display();

    list.insertAtIdx(1,23);
    list.insertAtIdx(4,63);
    list.insertAtIdx(10,55);

    list.display();
    list.deleteAtHead();
    list.display();

    list.deleteAtTail();
    list.display();

    list.deleteAtIdx(2);
    list.display();
    list.deleteAtIdx(9);
    cout<<endl;
    list.deleteAtIdx(4);
    list.display();

    cout<<list.getAtIdx(1)<<endl;
    cout<<list.getAtIdx(0)<<endl;
    cout<<list.getAtIdx(4)<<endl;
}