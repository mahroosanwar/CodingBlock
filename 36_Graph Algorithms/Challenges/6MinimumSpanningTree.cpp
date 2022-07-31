// 6: Minimum Spanning Tree

#include <bits/stdc++.h>
using namespace std;


class DSU
{
    int *parent;
    int *rank;

public:
    DSU(int n)
    {
        parent = new int[n];
        rank = new int[n];
        for (int i = 0; i < n; i++)
        {
            parent[i] = -1;
            rank[i] = 1;
        }
    }
    int find(int i)
    {
        if (parent[i] == -1)
            return i;
        return parent[i] = find(parent[i]);
        //->
    }
    void unite(int x, int y)
    {
        int s1 = find(x);
        int s2 = find(y);
        if (s1 != s2)
        {
            if (rank[s1] < rank[s2])
            {
                parent[s1] = s2; // updated
                rank[s2] += rank[s1];
                rank[s1] = 0;
            }
            else
            {
                parent[s2] = s1;
                rank[s1] += rank[s2];
                rank[s2] = 0;
            }
        }
    }
};
class graph
{
    vector<vector<int>> edgelist;
    int v;

public:
    graph(int v)
    {
        this->v = v;
    }
    void addedge(int x, int y, int w)
    {
        edgelist.push_back({w, x, y});
    }
    int kruskal_mst()
    {
        sort(edgelist.begin(), edgelist.end());
        DSU s(v);
        int ans = 0;
        for (auto edge : edgelist)
        {
            int w = edge[0];
            int x = edge[1];
            int y = edge[2];
            if (s.find(x) != s.find(y))
            {
                s.unite(x, y);
                ans += w;
            }
        }
        return ans;
    }
};
int main()
{
    /*graph g(4);
    g.addedge(0,1,1);
    g.addedge(1,3,3);
    g.addedge(3,2,4);
    g.addedge(2,0,2);
    g.addedge(0,3,2);
    g.addedge(1,2,2);*/
    int n, m;
    cin >> n >> m;
    graph g(n + 1);
    for (int i = 0; i < m; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        g.addedge(x, y, w);
    }
    cout << g.kruskal_mst() << endl;
    return 0;
}


// Given an undirected weighted graph with V nodes and E edges , find the weight of the minimum spanning tree. The IDs of the nodes are between 0 and n-1 inclusive.

// Note : Try using both Kruskal and Prim's Algorithm for this problem

// Input Format
// First line contains two integers V and E.
// Next E lines contain three space separated integers - u ,v and w
// u and v are the nodes , w = weight of edge

// Constraints
// 1 <= V <= 10000
// 1 <= E <= 100000
// 0 <= Weight of each edge <= 10000

// Output Format
// Display a single integer denoting the total weight of the minimum spanning tree.

// Sample Input
// 4 5
// 0 1 10
// 1 2 15
// 0 2 5
// 3 1 2
// 3 2 40
// Sample Output
// 17
// Explanation
// The edge between 2 & 3 with weight=15 and the edge between 3 & 4 with weight = 40 will not be a part of the final MST. The total weight of the remaining edges is 17.