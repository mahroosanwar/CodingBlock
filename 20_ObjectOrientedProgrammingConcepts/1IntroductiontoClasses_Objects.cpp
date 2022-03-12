// Introduction to Classes & Objects

#include <iostream>
using namespace std;


//Defining new data type
class Car{              //writting this does not accocate any memory in the programm
    int price;
    int model_no;
    char name[20];
};

int main(){
    //create object
    Car c;

    cout << sizeof(c)<< endl;
    cout << sizeof(Car) << endl;

    //for more information just create the array
    // Car a[20];
    // a[0] = c;            but before that create the car c
    return 0;
}
