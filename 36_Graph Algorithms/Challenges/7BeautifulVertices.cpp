// 7: Beautiful Vertices

/*The problem is simple implementation of DFS while maintaining a count of children of the vertices visited.
Let u be a vertex and v be its child. Then, check if children[v]>children[u].This way, check for each vertex 
while traversing the graph in DFS. One important thing to note that actually there are many trees in the 
input(a graph with no cycles and self loops is a tree). That means , you have to apply DFS for each of 
these trees.
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> adj[200000];
int child_count[100000];
int visited[123456];
long long happy = 0;
vector<int> master;
set<int> s;
int node, edge;

void dfs(int x)
{
    visited[x] = -1;
    for (int i = 0; i < adj[x].size(); i++)
    {

        if (visited[adj[x][i]] == 0)
        {
            dfs(adj[x][i]);
        }
    }
    visited[x] = 1;
    s.insert(x);
}

void dfs2(int x, int y)
{
    visited[x] = -1;

    for (int i = 0; i < adj[x].size(); i++)
    {
        if (visited[adj[x][i]] == 0)
        {
            dfs2(adj[x][i], x);
        }
    }

    visited[x] = 1;
    if (x != y)
    {
        if (child_count[x] > child_count[y])
            happy++;
    }
}

int main()
{
    cin >> node >> edge;

    for (int i = 1; i <= edge; i++)
    {
        int node1, node2;
        cin >> node1 >> node2;
        adj[node1].push_back(node2);
        adj[node2].push_back(node1);

        child_count[node1]++;
        child_count[node2]++;
    }

    for (int i = 1; i <= node; i++)
    {
        visited[i] = 0;
    }

    for (int i = 1; i <= node; i++)
    {
        if (visited[i] == 0)
        {
            dfs(i);
            master.push_back(*s.begin());
            s.erase(s.begin(), s.end());
        }
    }

    for (int i = 1; i <= node; i++)
    {
        vector<int>::iterator it;
        it = find(master.begin(), master.end(), i);
        if (it == master.end())
            child_count[i]--;
    }

    for (int i = 1; i <= node; i++)
    {
        visited[i] = 0;
    }

    for (int i = 0; i < master.size(); i++)
    {
        if (visited[master[i]] == 0)
        {
            dfs2(master[i], master[i]);
        }
    }
    cout << happy << endl;
    return 0;
}

// You are given a graph with N vertices and M edges. Master parent is the vertex which has no parent but may have 0 or more children. In any connected component of the graph, vertex with the lowest value in that component serves as the master parent. A vertex is called beautiful if it has more children than its parent. Count the number of beautiful vertices in the given graph. The graph has no cycles or self loops.

// Input Format
// First line consists of two space separated integers denoting N and M and the following M lines consist of two space separated integers X and Y denoting there is an edge between vertices X and Y.

// Constraints
// 1 <= N <= 100000 0 <= M <= N-1 1 <= x,y <= N

// Output Format
// Print the number of beautiful vertices in the graph.

// Sample Input
// 4 3
// 1 2
// 2 3
// 2 4
// Sample Output
// 1
// Explanation
// In this graph, we have vertices 1,2,3 and 4. Since 1 is the lowest among these, so it becomes the master vertex. Now, 1 has only 1 child while 2 has two children.So, 2 is a beautiful vertex. There are no more beautiful vertices in the graph.