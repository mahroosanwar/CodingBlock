//Replace pi

#include <iostream>
using namespace std;

void ReplacePi(char *a, int i){
    //base case
    if(a[i] == '\0' || a[i+1] == '\0'){
        return;
    }

    //recursive case

    if(a[i] == 'p' && a[i+1] == 'i'){
        int j = i + 2;
        //take the walue of j to null
        while(a[j] != '\0'){
            j++;
        }

        // shift the jth char to j+2
        while(j >= i+2){
            a[j+2] = a[j];
            j--;
        }
        //replace pi with 3.14

        a[i] = '3'; a[i+1] = '.'; a[i+2] = '1'; a[i+3] = '4';

        //Now recursion do for smaller string
        
        ReplacePi(a, i+4);      //i+4 bcz four char in 3.14
    }
    else{
        //ask the recursion to slove the smaller string from i+1
        ReplacePi(a, i+1);
    }
}
int main(){
    char a[] = "axpiaepixfpippi";

    cout << "Before Replacing Pi: " << a << endl;

    ReplacePi(a, 0);

    cout << "After Replacing Pi: " << a << endl;
}