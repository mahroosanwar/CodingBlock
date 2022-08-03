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


// It's winter season. There is a long queue of students from the four prime courses at Coding Blocks and everyone is here to grab his hoodie. Each student of a course has a different roll number. Whenever a new student will come, he will search for his friend from the end of the queue. Note that a student can only has friend from his course and not from any other course. As soon as he will find any of the friend in the queue, he will stand behind him, otherwise he will stand at the end of the queue. At any moment Kartik Bhaiya will ask the student, who is standing in front of the queue, to come and put his name and grab his hoodie and then remove that student from the queue. There are Q operations of one of the following types:

//1. E x y : A new student of course x whose roll number is y will stand in queue according to the method mentioned above.
//2. D : Kartik Bhaiya will ask the student, who is standing in front of the queue, to come and put his name for the hoodie and remove him from the queue.
// Find out the order in which student put their name.

// Note: Number of dequeue operations will never be greater than enqueue operations at any point of time.

// Input Format
// First line contains an integer Q, denoting the number of operations. Next Q lines will contains one of the 2 types of operations.

// Constraints
// 1 ≤ x ≤ 4 1 ≤ y ≤ 50000 1 ≤ Q ≤ 100000

// Output Format
// For each 2nd type of operation, print two space separated integers, the front student's course and roll number.

// Sample Input
// 5
// E 1 1
// E 2 1
// E 1 2
// D
// D
// Sample Output
// 1 1
// 1 2
