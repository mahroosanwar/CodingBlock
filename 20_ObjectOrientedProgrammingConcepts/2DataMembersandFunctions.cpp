//Data Members and Functions

#include <iostream>
using namespace std;

class Car{
//make data members public
public:
    float price;
    int model_no;
    char name[20];

    void print(){
        cout << "Price " << price << endl;
        cout << "Model " << model_no << endl;
        cout << "Name " << name << endl;
    }

    //this will not update the price
    float get_discount_price(float x){
        return price*(1.0 - x);
    }

    float Apply_Discount(float x){
        price = price * (1.0 - x);
        return price;
    }
};

int main(){
    Car c;
    c.price = 100;
    c.model_no = 112;
    c.name[0] = 'B';
    c.name[1] = 'M';
    c.name[2] = 'W';
    c.name[3] = '\0';

    // print 
    cout << "Name: " << c.name << "\nModel No: " << c.model_no << "\nPrice: " << c.price << endl;

    cout << "Enter the Discount you want:\n"; 
    float discount;
    cin >> discount;

    cout << "Final Price: " << c.get_discount_price(discount) << endl;      

    c.print();
    cout << endl << "Final Price after Discount " << c.Apply_Discount(discount) << endl;
    
    return 0;
}