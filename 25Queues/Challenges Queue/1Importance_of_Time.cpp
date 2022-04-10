// Importance of Time

#include<iostream>
#include<queue>
using namespace std;

int Importance_of_Time(queue<int> co, queue<int> io) {

    int time=0;
    while(!co.empty() && !io.empty()){

        //make co front element equal to ideal order
        while(co.front() != io.front()) {
            int temp = co.front();
            co.pop();
            co.push(temp);
            time++;
        }

        //co and io front become equal
        co.pop();
        io.pop();
        time++;
    }

    return time;
}

int main(){
    queue<int> co;
    queue<int> io;

    int n;
    cin >> n;

    for(int i=0; i<n; i++){
        int data;
        cin >> data;
        co.push(data);
    }

    for(int i=0; i<n; i++){
        int data;
        cin >> data;
        io.push(data);
    }

    cout << Importance_of_Time(co, io);

    return 0;
}
