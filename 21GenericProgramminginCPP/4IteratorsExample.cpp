//Iterator Example
//how to write generic search fun. with the help of iterator and templates

#include <iostream>
#include <list>
using namespace std;
// templates + iterators --> work for all types of containers ( vectors, list etc.)
template <class ForwardIterator, class T>
ForwardIterator Search(ForwardIterator start, ForwardIterator end, T key){

    while(start != end){
        if(*start == key){
            return start;
        }
        start++;
    }
    return end;
}

int main(){

    list<int > l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(5);
    l.push_back(3);

    auto it = Search(l.begin(), l.end(), 5);
    if(it == l.end()){
        cout << "Element not found";
    }
    else{
        cout << *it << endl;
    }
    return 0;
}