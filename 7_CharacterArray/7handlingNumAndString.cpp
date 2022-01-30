//handling numbers and string

#include <iostream>
using namespace std;

int main(){
    char a[1000];
    int n;
    cin >> n;
    cin.get();  //ignore the \n after the number
                //cin.ignore also do this
    for(int i=0; i<n; i++){
        cin.getline(a,1000);
        cout << a << endl;
    }


}