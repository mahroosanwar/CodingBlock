//4: BFS - Shortest Path

#include <bits/stdc++.h>
using namespace std;

//BFS SHORTEST PATH

class Graph{

public:

    map<int,list<pair<int, int> > > m;

    void edge_add(int src,int dest,int dist=6)
    {
        m[src].push_back(make_pair(dest,dist));
        m[dest].push_back(make_pair(src,dist));
    }

    void path(int src,map<int,int> &d)
    {
        map<int,int> distance;
     for(auto i:m){
         distance[i.first]=INT_MAX;
     }

        distance[src]=0;
        queue<int>q;
        q.push(src);
        while(!q.empty())
        {
            int s=q.front();
            q.pop();
            for(auto i:m[s])
            {
                pair<int,int>p=i;
                if(distance[p.first]>distance[s]+p.second)
                {
                    distance[p.first]=distance[s]+p.second;
                    q.push(p.first);
                    d[p.first]=distance[p.first];
                }
            }
        }
    }
};


int main() 
{
    int t;
    cin>>t;
    while(t--)
    {
        Graph g1;
        int n,m;
        int a,b;
        int src;
        cin>>n>>m;
        for(int i=0;i<m;i++)
        {
            cin>>a>>b;
            g1.edge_add(a,b);
        }
        map<int,int> d;
        cin>>src;
        g1.path(src,d);

        for(int i=1;i<=n;i++)
        {
            if(i!=src)
            {
                if(d.find(i)!=d.end()){
                    cout<<d[i]<<" ";
                }
                else
                {
                    cout<<"-1 ";
                }
            }
        }
        cout<<endl;
    }
}


// Consider an undirected graph consisting of 'n' nodes where each node is labeled from 1 to n and the edge between any two nodes is always of length 6 . We define node 's' to be the starting position for a BFS.

// Given 'q' queries in the form of a graph and some starting node, 's' , perform each query by calculating the shortest distance from starting node 's' to all the other nodes in the graph. Then print a single line of n-1 space-separated integers listing node s's shortest distance to each of the n-1 other nodes (ordered sequentially by node number); if 's' is disconnected from a node, print -1 as the distance to that node.

// Input Format
// The first line contains an integer,q , denoting the number of queries. The subsequent lines describe each query in the following format:

// 1: Each line contains N and M, the number of nodes and edges respectively.

// 2: The next m lines contains u and v means that there is edge between u and v .

// 3: The last line contains 's', the starting node.

// Constraints
// 1 <= q <= 10 2 <= n <= 1000 1 <= m <= (n*(n-1))/2 1 <= u,s,v <= n

// Output Format
// You have to print n-1 integer denoting the shortest distance from s to all other nodes excluding s itself.

// Sample Input
// 2
// 4 2
// 1 2
// 1 3
// 1
// 3 1
// 2 3
// 2
// Sample Output
// 6 6 -1
// -1 6