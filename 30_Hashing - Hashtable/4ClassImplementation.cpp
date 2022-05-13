//Class Implementation

//implement hashmap
//separate chaining technique

#include<iostream>
#include<string>
using namespace std;

template<typename T>

class Node{

public:
    string  key;
    T value;
    Node<T> *next;

    Node(string key, T val) {
        this-> key = key;
        value == val;
        next = NULL;
    }

    //deconstructor helpful when we removed from LL
    ~Node() {
        if(next != NULL) {
            delete next;
        }
    }
};

template<typename T> 
class HashTable{
    
    Node<T>**table;       //pointer to the array of pointers
    int current_size;        //how many element enter in table till now
    int table_size;

public:
    HashTable(int ts = 7) {
        table_size = ts;
        table = new Node<T>*[table_size];
        current_size  = 0;
        for(int i=0; i<table_size; i++) {
            table[i] = NULL;
        }
    }
};


int main() {

}
