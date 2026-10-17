#include<iostream>
using namespace std;
class Student{ // User Defined Data Type
public:
    string name;
    int rno;
    float cgpa;
    // Constructor Overloading
    Student(string n, float c, int r){ // Parameterised Constructor
        rno = r;
        name = n;
        cgpa = c;
    }
    Student(int r, float c, string n){ // Parameterised Constructor
        rno = r;
        name = n;
        cgpa = c;
    }
    Student(string n, int r){ // Parameterised Constructor
        rno = r;
        name = n;
    }
    Student(){ // Default Constructor
        
    }
};
int main(){
    Student x("Sumit",8.7,39); 
    cout<<x.name<<" "<<x.rno<<" "<<x.cgpa<<endl;

    Student y(1049,9.75,"Manish"); 

    Student z("Ikram",42); 

    Student alpha;
}