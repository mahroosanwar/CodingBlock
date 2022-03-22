//List STL Example - Adjacency List for Weighted Graph

#include <iostream>
#include <list>
using namespace std;

int main(){

    //list to create graph data structure

    list <pair<int , int> > *l;     //l is taken as pointer // so we use dynamic array

    int n;
    cin >> n;

    l = new list <pair <int, int> >[n];

    int e;      //no of edge
    cin >> e;

    for(int i=0; i<e; i++){
        int x, y, wt;
        cin >> x >> y >> wt;
        l[x].push_back(make_pair(y, wt));
        l[y].push_back(make_pair(x, wt));
    }

    //print the linked list
    for(int i=0; i<n; i++){
        //print every linked list
        cout << "Linked List: " << i << " --> ";
        for(auto xp:l[i]){      //every linked list is going to be a pair
            cout  << '(' << xp.first << ',' << xp.second << "),"; 
        }
        cout << endl;
    }

    return 0;
}