// 3: Pairing

#include <iostream>
#include <list>
#include <map>
using namespace std;

template <typename T>
class Graph
{
    list<int> *l;
    int V;

public:
    Graph(int V)
    {
        this->V = V;
        l = new list<int>[V];
    }

    void addEdge(int x, int y)
    {
        l[x].push_back(y);
        l[y].push_back(x);
    }

    void dfs_helper(T src, map<T, bool> &visited, long long int &cntn)
    {

        visited[src] = true;
        cntn++;

        for (auto nbr : l[src])
        {
            if (!visited[nbr])
            {
                dfs_helper(nbr, visited, cntn);
            }
        }
    }

    void dfs()
    {
        map<T, bool> visited;

        for (int i = 0; i < V; i++)
        {
            visited[i] = false;
        }

        long long int cnt_sub = 0;
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                long long int cntn = 0;
                dfs_helper(i, visited, cntn);
                long long int ans = (cntn) * (cntn - 1) / 2;
                cnt_sub += ans;
            }
        }
        long long int total = (V) * (V - 1) / 2;
        cout << total - cnt_sub << endl;
    }
};

int main()
{
    int nodes, edges;
    cin >> nodes >> edges;
    Graph<int> g(nodes);

    for (int i = 0; i < edges; i++)
    {
        int x, y;
        cin >> x >> y;
        g.addEdge(x, y);
    }
    g.dfs();
}

// There are N cities numbered from 0 to N-1. You have to choose 2 cities such that there is no path from first city to second city .
// You are given information in the form of M pairs (X,Y) i.e there is an undirected road between city X and city Y.
// Find out the number of ways in which cities can be chosen.

// Input Format
// The first line contains two integers, N and M separated by a single space. M lines follow. Each line contains integers separated by a single space X and Y denoting road between X and Y.

// Constraints
// 1 <= N <= 100000 1 <= M <= 100000 0 <= X,Y <= N-1

// Output Format
// An integer that denotes the number of permissible ways to choose a pair of cities.

// Sample Input
// 5 3
// 0 1
// 2 3
// 0 4
// Sample Output
// 6
// Explanation
// 0 1 4 cannot be reached by 2 hence (2,0) (2,1) (2,4) and also 0 1 4 cannot be reached by 3 so (3,0) (3,1) (3,4) hence 6 ways.