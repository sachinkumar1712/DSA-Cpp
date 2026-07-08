//array by default pass by reference but in case of objects it is pass by value and 
// vector by default pass by value but in case of objects it is pass by reference
#include<iostream>
using namespace std;
class Student{//class declaration
    public:
    string name;
    int rno;
    float marks;
    // Student(string n, int r, float m){//parameterized constructor
    //     name = n;
    //     rno = r;
    //     marks = m;
    // }  
      Student(string name, int rno, float marks){//parameterized constructor
        this->name = name;
        this->rno = rno;
        this->marks = marks;
    }  

};

// void change(Student s){//pass by value
//     s.name = "Rahul";
//     s.rno = 22;
//     s.marks = 99.5;
// }


// void change(Student &s){//pass by reference
//     s.name = "Rahul";
//     s.rno = 22;
//     s.marks = 99.5;
// }   

void change(Student* s){//pass by reference
    s->name = "Rahul";
    s->rno = 22;
    s->marks = 99.5;
} 

int main(){
    // Student s("Sachin", 21, 94.5);//object creation and initialization using parameterized constructor
    
    // Student*ptr = &s;
    // int x = 6;
    // int*p = &x;
    // *p = 8;
    // cout<<x<<endl;
    // cout<<(*ptr).name<<endl;//dereferencing pointer to access object members
    // cout<<s.name<<endl;
    // (*ptr).name = "Harsh";//dot operator
    // cout<<s.name<<endl;
    // ptr->name = "Rohit";//arrow operator
    // cout<<s.name<<endl;

    // change(&s);//function call
    // cout<<s.name<<endl;
    // cout<<s.marks<<endl;
    // cout<<s.rno<<endl;




    // Student s;//decelaration
    // s.name = "Sachin";//initialization
    // s.rno = 21;
    // s.marks = 94.5;
    // cout<<s.name<<endl;
    // cout<<s.marks<<endl;
    // cout<<s.rno<<endl;
    // change(s);//function call
    // cout<<s.name<<endl;
    // cout<<s.marks<<endl;
    // cout<<s.rno<<endl;


    Student*s = new Student("Sachin", 21, 94.5);//dynamic memory allocation
    cout<<s->name<<endl;
    cout<<s->rno<<endl;
    cout<<s->marks<<endl;

    change(s);//function call

    cout<<s->name<<endl;
    cout<<s->rno<<endl;
    cout<<s->marks<<endl;



}