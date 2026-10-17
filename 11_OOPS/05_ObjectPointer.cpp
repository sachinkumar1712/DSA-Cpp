#include<iostream>
using namespace std;
class Cricketer{
public:
    string name;
    int runs;
    float average;
    Cricketer(string name, int runs, float average){
        (*this).name = name;
        this->runs = runs;
        this->average = average;
    }
    void print(){
        cout<<name<<endl;
        cout<<runs<<endl;
        cout<<average<<endl;
    }
};
int main(){
    Cricketer c1("Virat Kohli",14000,58.1);
    Cricketer c2("Sachin Tendulkar Sir",18000,46.7);
    Cricketer c3("Rohit Sharma",11000,49.4);

    Cricketer* p = new Cricketer("ABD",10000,55.2); // Object Pointer
    p->print();
    
    Cricketer* ptr = &c1; // Object Pointer
    ptr->average = 74.2; // (*ptr).average = 74.2;
    cout<<c1.average<<endl;
    cout<<ptr->name<<endl;
    cout<<ptr->runs<<endl;
    
    // int x = 10;
    // int* ptr = &x;
    // *ptr = 20; 
    // cout<<x<<endl;

    int x = 10;
    int* y = new int(10);
}