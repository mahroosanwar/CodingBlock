//Comparator Class


#include <iostream>
#include <list>
#include <vector>
using namespace std;

class Book{
public:
    string name;
    int price;

    Book(){

    }

    Book(string name, int price){
        this->name = name;
        this->price = price;
    }
};

class BookCompare{
public:
    bool operator()(Book A, Book B){
        if(A.name == B.name){
            return true;
        }
        return false;
    }
};

// templates + iterators + conmpare
//so we got freedom form custom datatype, custom comparison, underlying container
template <class ForwardIterator, class T, class compare>
ForwardIterator Search(ForwardIterator start, ForwardIterator end, T key, compare cmp){

    while(start != end){
        if(cmp(*start,key)){
            return start;
        }
        start++;
    }
    return end;
}

int main(){
    Book b1("C++", 100);        //old edition of book
    Book b2("python", 120);
    Book b3("java", 130);

    // Book b4(b1);

    list <Book> l;
    // vector <Book> l;         // work for this too 
    l.push_back(b1);
    l.push_back(b2);
    l.push_back(b3);
    
    Book booktofind("C++", 110);  //new edition of book

    BookCompare cmp;

    // if(cmp(b1, booktofind)){
    //     cout << "Same Book! " << endl;
    // }
    // list<book> :: iterator it = Search(l.begin(), l.end(), booktofind, cmp;)
    auto it = Search(l.begin(), l.end(), booktofind, cmp);
    if(it!=l.end()){
        cout << "Book find in library! " << endl;
    }
    else{
        cout << "Not Found! ";
    }
   return 0;
}