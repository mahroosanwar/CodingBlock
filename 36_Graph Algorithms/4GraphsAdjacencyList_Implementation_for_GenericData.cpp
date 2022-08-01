//Graphs Adjacency List Implementation for Generic Data

#include<iostream>
#include<unordered_map>
#include<list>
#include<cstring>
using namespace std;

class Graph {
    //adjacent list
    unordered_map<string, list<pair<string, int>> > l;

public:
    void addEdge(string x, string y, bool bidir, int wt) {

        l[x].push_back(make_pair(y, wt));

        if(bidir) {
            l[y].push_back(make_pair(x, wt));
        }
    }

    void printAdjList() {
        //Iterate over all the keys in a map
        for(auto p : l) {
            string city = p.first;
            list<pair<string, int> > nbrs = p.second;           //nbrs : neghbours

            cout << city << " -> ";

            for(auto nbr : nbrs) {              //nbr: neighbour
                string dest = nbr.first;        //destination

                int dist = nbr.second;          //distance

                cout << dest << " " << dist << " ";
            }
            cout << endl;
        }
    }
};

int main() {

    Graph g;
    g.addEdge("A", "B", true, 20);      //where "true/false shows uni/bi directional & 20 shows weight(ex: distance) b/w nodes"
    g.addEdge("B", "D", true, 40);
    g.addEdge("A", "C", true, 10);
    g.addEdge("C", "D", true, 40);
    g.addEdge("A", "D", false, 50);

    g.printAdjList();
    
    return 0;
}
