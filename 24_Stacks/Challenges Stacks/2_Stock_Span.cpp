// Stock Span

#include<iostream>
#include<stack>
using namespace std;

void stockSpan(int *price, int n) {
    
    stack<int> s;
    int span[n] = {0};
    
    s.push(0);
    span[0] = 1;

    //loop for rest of the days ->O(N) -> push and pop each element only once!
    for(int i=1 ; i<n; i++){
        int currPrice = price[i];

        while(!s.empty() && price[s.top()]<=currPrice){
            s.pop();
        }

        if(!s.empty()) {
            span[i] = i-s.top();
        }
        else{
            span[i] = i+1;      //corner case-> if the price is highest after 0 index so stack become empty
                                //so we have to do index of the current day + 1
        }

        //push this element into the stack
        s.push(i);
    }

    
    for(int i=0; i<n; i++){
        cout << span[i] << " ";
    }
    cout << "END" << endl;
}

int main(){
    int n;
    cin >> n;

    int a[n];

    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    stockSpan(a, n);

    return 0;
}

