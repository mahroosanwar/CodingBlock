//Destructors

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
        cout << "Inside the copy constructor" << endl;
        price = X.price;
        model_no = X.model_no;
        //logic to create deep cpy  
        name = new char[strlen(X.name)+1];
        strcpy(name, X.name);
    }

    //for copy assignment
    void operator=(Car &X){
        price = X.price;
        model_no = X.model_no;
        //logic to create deep cpy in copy assignment
        name = new char[strlen(X.name)+1];
        strcpy(name, X.name);
    }

    //print fun
    void print(){
        cout << "Name: " << name << endl;
        cout << "Model no.: " << model_no << endl;
        cout << "Price: " << price << endl;
    } 

    //destructors function looks like
    // ~Car(){
    //     cout << "inside destructors of Car " << name << endl;       //not this part;
    // }

    //deleting dynamic allocated data members of that class     (--> reverse order first d then c)
    ~Car(){
        cout << "Destroy Car " << name << endl;
        if(name != NULL){
            delete [] name;
        }
    } 
};

int main(){
    //static car object --> it will delete automatically
    Car c(100, 200, "BMW");         //calling parametrize constructor
    Car d;//constructor
    d = c;      //copy assignment --> it will not call copy counstuctor not same as [ Car d = c; ]
                //adv. --> call copy assignment as many times 

    d.set_price(400);       //change the price of d
    d.name[0] = 'A';    //here is problem it changes the name[0] in both  c & d "AMW" when we created shallow copy
                        //but to oveer come this ew make deep cpy then it will work fine
    c.print();

    d.print();

    //Dynamically Created car --> where e denotes pointer
    Car *e = new Car(10, 20, "Farari");

    e->print();
    
    //to delete dynamic allocated objects 
    delete e;
     
    return 0;
}