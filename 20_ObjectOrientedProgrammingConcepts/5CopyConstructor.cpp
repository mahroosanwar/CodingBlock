// Copy Constructor

#include <iostream>
#include <cstring>
using namespace std;

//access specifier public & private

class Car{
//make datamember private
private:
    float price;
    
//make data members public
public:
    int model_no;
    char name[20];

    void print(){
        cout << "Price: " << price << endl;
        cout << "Model: " << model_no << endl;
        cout << "Name: " << name << endl;
    }
    //default constructor
    // Car(){
            
    // }

    Car(){
        cout << "Inside the car Constructor" << endl;
    }
    //Parameterized constructor 
    //Assign some initial values to data members
    Car(int p, int m, char *n){
        price = p;
        model_no = m;
        strcpy(name, n);        //copy the n to the name variable
    }


    //How copy constructor look like (hidden)
    Car(Car &x){
        cout << "Copy Constructor " << " ";
        price = x.price;
        model_no = x.model_no;
        strcpy(name, x.name);
    }

    //this will not update the price
    float get_discount_price(float x){
        return price*(1.0 - x);
    }

    float Apply_Discount(float x){
        price = price * (1.0 - x);
        return price;
    }

    // give access to set price with conditions
    void set_price(float p){
        float msp = 111;
        if(p>msp){
            price = p;
        }
        else{
            price = msp;
        }
    }

    //give access to read price
    float get_price(){
        return price;
    }

};

int main(){
    Car c;                  //it makes a call to constructor function present inside the class 
                            //constructor fun is hidden and created by the compiler
                            //Call of constructor will be 3 times for a, b, c

    Car d(222, 223, "Audi");

    Car e(d);                   //copy constructor
    cout << "Car D: " << endl;
    d.print();
    cout << endl;

    cout << "Car E: " << endl;
    e.set_price(424);
    e.print();
    cout << endl;

    //Another way to make the copy constructor
    Car f = e;

    c.model_no = 112;
    c.name[0] = 'B';
    c.name[1] = 'M';
    c.name[2] = 'W';
    c.name[3] = '\0';

    c.set_price(-199);

    cout << "\nEnter the Discount you want:\n"; 
    float discount;
    cin >> discount;

    cout << "Final Price: " << c.get_discount_price(discount) << endl;      

    c.print();
    cout << endl << "Final Price after Discount " << c.Apply_Discount(discount) << endl;
    
    return 0;
}