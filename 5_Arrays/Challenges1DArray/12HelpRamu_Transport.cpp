// Hepl remu in transport (rickshwa and cab)

#include <iostream>
using namespace std;

int min(int a, int b){
    return (a < b) ? a : b ;
}

void TicketCost(int c[], int n, int m, int a[], int b[]){
    int sum_rick_c1 = 0, sum_cab_c1 = 0;
    for(int i=0; i<n; i++){                         //for total rickshaw ticket cost
        int rick_c1 = min((a[i]*c[0]), c[1]);       //min of (one ride cost * no. of times ride) and unlimited ride cost for some cab or some rickshaw   
        sum_rick_c1 += rick_c1;
    }
    int totalRickshawCost = min(sum_rick_c1, c[2]); //min of (mim in above case) and unlimited ride cost for all cab or all rickshaw

    for(int i=0; i<m; i++){                         //for total cab ticket cost 
        int cab_c1 = min((b[i]*c[0]), c[1]);
        sum_cab_c1 += cab_c1;
    }
    int totalCabCost = min(sum_cab_c1, c[2]);

    int total_ticket_cost = min((totalRickshawCost + totalCabCost) , c[3]);
    cout << total_ticket_cost << endl;
}

int main(){
    int t;              //number of testcase
    cin >> t;

    for(int i=0; i<t; i++){
        int c[4];               
        for(int i=0; i<4; i++){
            cin >> c[i];        //c1, c2, c3, c4 types of tickets
        }
        int n,m;                
        cin >> n >> m;         //number of rickshwas and cabs resp.
        int a[n];
        for(int i=0; i<n; i++){
            cin >> a[i];            //number of ride taken by rickshwa
        }
        int b[m];
        for(int i=0; i<m; i++){
            cin >> b[i];            //number of rides taken by cabs
        }
        TicketCost(c,n,m,a,b);
    }

    cout << endl;
    return 0;
}


// before moving to next test case, just initialize t1 & t2 to 0, as u had declared them globally…
// This Question is Quite Interesting to read as there remains lots of confusion while reading it. This is because of the amount of data provided in the question is a lot. Every student found himself stuck in the data provided in the question.

// Let’s make it a simple one, for this first i need to make sure you are full aware while reading the solution for which i want to give u an example of what exactly we are going to do in this Question.

// Example : Suppose you are buying Maggie packet and the shopkeeper has 2 types of packets available which are as follows :- 1 kg 500 Rs and 0.5 Kg 240 Rs and your need is to buy 1 Kg Maggie so in this case obviouly you will buy 2 Half Kgs packets as it will cost 480 Rs and 1 Kg is of 500 Rs …. I know you all have made this calculation . :-]

// Same we are going to implement in this Question.

// c1 - Ticket cost for 1 ride on rickshaw or cab.
// c2 - Ticket cost for unlimited rides on some rickshaw or cabs.

// Now if you have 2 cabs and if you have only these 2 types of tickets available then obviously just like the above example you will first check the cost of buying Two c1 tickets and cost of 1 c2 Ticket. Among them the minimum cost willl be your answer. Now consider 1 more ticket which says c3 is the cost of ride on all rickshaws or on all cabs. then obviously now you will check the minimum cost of buying individual c1 ticket for each ride or c2 ticket for some rickshaw or on some cabs or c3 ticket for all rickshaws or all cabs.

// Now assume there is 1 more ticket saying unlimited cost for ride on all rickshaws and all cabs. Here your final answer will be the minimum cost of previously calculated cost using c1, c2 and c3 tickets and cost of c4 ticket.