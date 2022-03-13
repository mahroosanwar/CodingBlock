//Shallow and Deep Copy

#include <iostream>
#include <cstring>
using namespace std;

class Car{
private:
    int price;

public:
    int model_no;
    char *name;         //insted of making an array making pointer towards dynamic array

    Car(){
        name = NULL;        //in the constructor say this pointer as null 
    }
    void set_price(float p){
        price = p;
    }

    // call parametrize constructor  
    Car(float p, int m, char *n){
        price = p;
        model_no = m;
        name = new char[strlen(n)+1];           //+1 for null character
        strcpy(name, n);
    }
    //for Deep cpy
    Car(Car &X){
        price = X.price;
        model_no = X.model_no;
        //logic to create deep cpy
        name = new char[strlen(X.name)+1];
        strcpy(name, X.name);
    }
    //print fun
    void print(){
        cout << "Name: " << name << endl;
        cout << "Model no.: " << model_no << endl;
        cout << "Price: " << price << endl;
    } 
};

int main(){
    Car c(100, 200, "BMW");         //calling parametrize constructor
    Car d(c);                       //calling cpoy constructor

    d.set_price(400);       //change the price of d
    d.name[0] = 'A';    //here is problem it changes the name[0] in both  c & d "AMW" when we created shallow copy
                        //but to oveer come this ew make deep cpy then it will work fine
    c.print();

    d.print();

    return 0;
}