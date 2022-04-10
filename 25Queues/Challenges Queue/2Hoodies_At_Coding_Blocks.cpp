// Hoodies At Coding Blocks

#include<iostream>
#include<queue>
using namespace std;

void hoodies(int q) {

    //make queue for four course
    queue<int> q1;
    queue<int> q2;
    queue<int> q3;
    queue<int> q4;
    
    queue<int> group_order;     //to maintain who have comes first

    bool isOne = false;
    bool isTwo = false;
    bool isThree = false;
    bool isFour = false;

    for(int i=0; i<q; i++) {
        char ch;
        cin >> ch;

        //enqueue
        if(ch == 'E') {
            int x, y;
            cin >> x >> y;

            if(x==1) {
                q1.push(y);

                //if 1 come first push in group_order
                //and rest of his friends behind him
                if(!isOne) {
                    group_order.push(1);
                    isOne = true;
                }
            }
            else if(x==2) {
                q2.push(y);

                if(!isTwo) {
                    group_order.push(2);
                    isTwo = true;
                }
            }
            else if(x==3) {
                q3.push(y);

                if(!isThree) {
                    group_order.push(3);
                    isThree = true;
                }
            }
            else{
                q4.push(y);

                if(!isFour) {
                    group_order.push(4);
                    isFour = true;
                }
            }
        }

        // dequeue
        if(ch == 'D') {
            //course that come first
            int front = group_order.front();

            if(front==1) {

                if(!q1.empty()) {
                    cout << 1 << " " << q1.front() << endl;
                    q1.pop();
                }

                if(q1.empty()) {
                    group_order.pop();
                    isOne = false;
                }
            }

            else if(front==2) {

                if(!q2.empty()) {
                    cout << 2 << " " << q2.front() << endl;
                    q2.pop();
                }

                if(q2.empty()) {
                    group_order.pop();
                    isTwo = false;
                }
            }

            else if(front==3) {

                if(!q3.empty()) {
                    cout << 3 << " " << q3.front() << endl;
                    q3.pop();
                }

                if(q3.empty()) {
                    group_order.pop();
                    isThree = false;
                }
            }

            else {

                if(!q4.empty()) {
                    cout << 4 << " " << q4.front() << endl;
                    q4.pop();
                }

                if(q4.empty()) {
                    group_order.pop();
                    isFour = false;
                }
            }
        }
    }
}

int main(){
    int q;
    cin >> q;

    hoodies(q);

    return 0;
}