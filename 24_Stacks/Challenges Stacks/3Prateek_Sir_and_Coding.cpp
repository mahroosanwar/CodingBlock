//Prateek Sir and Coding

#include<iostream>
#include<stack>
using namespace std;

void manage_costModule(int n){

    stack<int> s;

    while(n--){
        int quary;
        cin >> quary;

        if(quary == 2){
            int price;
            cin >> price;

            s.push(price);
        }
        else{
            if(!s.empty()){
                cout << s.top() << endl;
                s.pop();
            }
            else{
                cout << "No Code" << endl;
            }
        }
    }
}

int main(){
    int n;
    cin>> n;

    manage_costModule(n);

    return 0;
}