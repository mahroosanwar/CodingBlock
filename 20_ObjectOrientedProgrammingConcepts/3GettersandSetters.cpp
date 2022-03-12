// Getters and Setters

#include <iostream>
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
    Car c;
    // c.price = 100;  --> cann't initialze bcz it's private 
    c.model_no = 112;
    c.name[0] = 'B';
    c.name[1] = 'M';
    c.name[2] = 'W';
    c.name[3] = '\0';

    // print 
    // cout << "Name: " << c.name << "\nModel No: " << c.model_no << "\nPrice: " << c.price << endl;
    c.set_price(-199);

    cout << "Enter the Discount you want:\n"; 
    float discount;
    cin >> discount;

    cout << "Final Price: " << c.get_discount_price(discount) << endl;      

    c.print();
    cout << endl << "Final Price after Discount " << c.Apply_Discount(discount) << endl;
    
    return 0;
}

