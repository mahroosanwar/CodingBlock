//OOPS Webinar | Operator Overloading
//Que--> complex in, out, add, sub, multiply, real, imaginary parts

#include <iostream>
using namespace std;

class complex{
    int real;
    int img;

public:
    complex(){
        real = 0;
        img = 0;
    }

    //parametrized constructor
    complex(int r, int i){
        real = r;
        img = i;
    }

    //copy comstruct
    //it extst by default
    
    //use const bcz we don't want to change them and it's not apdating any parameter
    void setReal(const int r){      
        real = r;
    }
    void setImg(const int i){
        img = i;
    }

    int getReal() const{
        return real;
    }
    int getImg() const{
        return img;
    }
    //print them
    void print(){
        if(img>0){
            cout << real << " + " << img << "i" << endl;
        }
        else{
            cout << real << " - " << -img << "i" << endl;
        }
    }

    void add(const complex &x){       //pass c2 as reference variable in x,  parameter const not function
        real += x.real;
        img += x.img;
    }

    void operator+(const complex &x){
        real += x.real;
        img += x.img;
    }

    void operator!(){
        img *= -1;
    }

    // void operator[](string s){
    //     cout << real << " + " << img << s << endl;
    // }

    int operator[](string s){
        if(s=="real"){
            return real;
        }
        else{
            return img;
        }
    }
};

//take in/op as complex using << , >> operators (so fun define in global)

// void operator>>(istream& is, complex &c){
//     int r1, i1;
//     is >> r1 >> i1;
//     c.setReal(r1);
//     c.setImg(i1);
// }

// void operator<<(ostream& os, complex &c){
//     c.print();
// }

//return type cin/cout  (istream / ostream) than it will work for more than one complex in / op
istream& operator>>(istream& is, complex &c){
    int r1, i1;
    is >> r1 >> i1;
    c.setReal(r1);
    c.setImg(i1);
    return is;
}
ostream& operator<<(ostream& os, complex &c){
    c.print();
    return os;
}


int main(){
    complex c1(5, 3);
    complex c2;
    c2.setReal(1);
    c2.setImg(4);

    c1.print();
    c2.print();

    // // c1.add(c2);                //this will update c1 as c1 + c2
    // c1.print();
    // c2.print();                 // but c2 not change

    c1 + c2;
    c1.print();                     //this will update c1 as c1 + c2
    c2.print();                     //but c2 not change

    !c1;
    c1.print();

    // c1[" is cool "];
    // c1.print();
    
    cout << c1["real"] << endl;
    cout << c1["img"] <<  endl;

    // complex d;
    // cin >> d;
    // cout << d;

    complex d1, d2;
    cin >> d1 >> d2;
    cout << d1 << d2;
    return 0;
}