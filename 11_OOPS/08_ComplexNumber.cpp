#include<iostream>
using namespace std;
class Complex{
public:
    float real;
    float imaginary;
    Complex(int real, int imaginary){
        this->real = real;
        this->imaginary = imaginary;
    }
    void print(){
        if(imaginary < 0)
            cout<<real<<" - "<<-imaginary<<"i"<<endl;
        else 
            cout<<real<<" + "<<imaginary<<"i"<<endl;
    }
    void add(Complex c){
        real = real + c.real;
        imaginary = imaginary + c.imaginary;
    }
    void multiply(Complex c){
        real = real * c.real - imaginary * c.imaginary;
        imaginary = real * c.imaginary + imaginary * c.real;
    }
};
int main(){
    Complex c1(3,7); // 3 + 7i
    Complex c2(2,4); // 2 + 4i
    c1.print();
    c1.multiply(c2);
    c1.print();
}