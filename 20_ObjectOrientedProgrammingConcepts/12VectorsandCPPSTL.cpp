// /Vectors and C++ STL

//create class  vectors (user define function)

#include <iostream>
using namespace std;

class vector{
    //data member and some function
    int *arr;
    int cs;             //current size
    int maxSize;

public:

    //constructor of vector
    vector(int defaultSize = 4){        //if user does not give size so default size  = 4;
        maxSize = defaultSize;
        cs = 0;
        arr = new int[maxSize];
    }

    void push_back(int data){
        if(cs == maxSize){
            //doubling operation
            int *oldArr = arr;
            arr = new int[2*maxSize];
            maxSize *= 2;

            for(int i=0; i<cs; i++){
                arr[i] = oldArr[i];
            }

            //delete older Arr
            delete [] oldArr;
        }
        arr[cs] = data;
        cs++;
    }

    bool empty(){
        return cs==0;
    }

    //shrink arr

    void pop_back(){
        if(!empty()){
            cs--;
        }
    }

    int getSize(){
        return cs;
    }

    int getMaxSize(){
        return maxSize;
    }

    void print(){
        for(int i=0; i<cs; i++){
            cout << arr[i]  << " ";
        }
    }

    int at(int i){      //get ith element
        return arr[i];
    }

    //operator over user defined [], (), !, +, -, *, /, etc;

    //box return by reference
    int& operator[](int i){
        return arr[i];
    }

};
// 'void' removed with ostream& and return os to make this operator work for more than one vector
ostream& operator<<(ostream &os, vector &v){
    os << "\nin << operator" << endl;
    v.print();
    return os;
}

int main(){
    vector v;

    for(int i=0; i<=3; i++){
        v.push_back(i*i);
    }
    
    cout << v.getMaxSize() << endl;
    v.push_back(7);
    cout << v.getMaxSize() << endl;
    v.print();
    
    //operator[] use 
    cout << endl << v[1] << endl;

    for(int i=0; i<v.getSize(); i++){
        cout << v[i] << " ";
    }
    vector fun;
    fun = v;
    cout << v << fun;

    v[2] = 8;
    v[2] += 6;
    cout << endl <<  v[2] << endl;
    return 0;
}

