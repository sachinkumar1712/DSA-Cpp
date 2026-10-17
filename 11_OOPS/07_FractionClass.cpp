#include<iostream>
using namespace std;
class Fraction{
public:
    int num;
    int den;
    Fraction(int num, int den){
        this->den = den;
        this->num = num;
        simplify();
    }
    void print(){
        cout<<num<<"/"<<den<<endl;
    }
    void multiply(Fraction f){
        num = num * f.num;
        den = den * f.den;
        simplify();
    }
    void add(Fraction f){
        num = num * f.den + den * f.num;
        den = den * f.den;
        simplify();
    }
    void simplify(){
        int hcf = gcd(num,den);
        num /= hcf;
        den /= hcf;
    }
    int gcd(int a, int b){
        if(a == 0) return b;
        return gcd(b%a, a);
    }
};

// Fraction multiply(Fraction& f1, Fraction& f2){
//     Fraction res;
//     res.num = f1.num * f2.num;
//     res.den = f1.den * f2.den;
//     return res;
// }

int main(){
    Fraction f1(2,5);
    Fraction f2(3,5);
    f1.print();
    f1.add(f2); 
    f1.print();

    Fraction f3(6,8);
    f3.print();

    // int x = 10;
    // int y = 20;
    // x *= y; // x = 200 y = 20
}