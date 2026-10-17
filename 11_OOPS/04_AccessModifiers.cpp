#include<iostream>
using namespace std;
class Cricketer{
private:
    int runs;
    string name;
    float average;
public:
    Cricketer(string name, int runs, float average){
        (*this).name = name;
        this->runs = runs;
        this->average = average;
    }
    void print(){ // getter
        cout<<name<<endl;
        cout<<runs<<endl;
        cout<<average<<endl;
    }
    int getRuns(){ // getter
        return runs;
    }
    void setRuns(int runs){ // setter
        this->runs = runs;
    }
};
int main(){
    Cricketer c("Virat Kohli",14000,58.1);
    // cout<<c.runs<<endl; // ERROR
    cout<<c.getRuns()<<endl;
    c.setRuns(15000);
    cout<<c.getRuns()<<endl;
}