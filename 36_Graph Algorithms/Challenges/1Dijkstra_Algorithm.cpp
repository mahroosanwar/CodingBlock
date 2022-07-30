// 1: Dijkstra's Algorithm

#include <bits/stdc++.h>
using namespace std;

int Getmin(int distance[], bool sptSet[], int V)
{
    int min = INT_MAX;
    int index = -1;
    for (int i = 1; i <= V; i++)
    {
        if (distance[i] <= min && sptSet[i] == false)
        {
            min = distance[i];
            index = i;
        }
    }

    return index;
}

void dijkstra(vector<pair<int, int>> adj[], int s, int V)
{
    bool sptSet[500];
    int distance[500];
    for (int i = 1; i <= V; i++)
    {
        distance[i] = INT_MAX;
        sptSet[i] = false;
    }
    distance[s] = 0;
    for (int i = 1; i <= V; i++)
    {
        int u = Getmin(distance, sptSet, V);
        sptSet[u] = true;
        int len = adj[u].size();
        for (int j = 0; j < len; j++)
        {
            if (!sptSet[adj[u][j].first] && distance[adj[u][j].first] > distance[u] + adj[u][j].second)
                distance[adj[u][j].first] = distance[u] + adj[u][j].second;
        }
    }
    for (int i = 1; i <= V; i++)
    {
        if (distance[i] < 0 || distance[i] == INT_MAX)
            distance[i] = -1;
        if (i != s)
            cout << distance[i] << " ";
    }
    cout << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<pair<int, int>> adj[500];
        for (int i = 0; i < m; i++)
        {
            int x, y, r;
            cin >> x >> y >> r;
            adj[x].push_back(make_pair(y, r));
            adj[y].push_back(make_pair(x, r));
        }
        int s;
        cin >> s;
        dijkstra(adj, s, n);
    }
    return 0;
}

// Given a graph consisting 'N' nodes (labeled 1 to N) where a specific given node 'S' represents the starting position and an edge between two nodes is of a given length, which may or may not be equal to other lengths in the graph.

// It is required to calculate the shortest distance from the start position (Node 'S') to all of the other nodes in the graph.

// If a node is unreachable, the distance is assumed as -1.

// Input Format
// The first line contains T, denoting the number of test cases. First line of each test case has two integers N, M denoting the number of nodes in the graph and, denoting the number of edges in the graph.

// The next M lines each consist of three space-separated integers x,y,r where x and y denote the two nodes between which the undirected edge exists, 'r' denotes the length of edge between these corresponding nodes.

// The last line has an integer, 'S' denoting the starting position.

// Constraints
// 1 <= N <= 3000 1 <= M <= (N*(N-1))/2 1 <= x,y <= N 1 <= r <= 10^5

// Output Format
// For each of the T test cases, print a single line consisting N-1 space separated integers denoting the shortest distance of N-1 nodes other than from starting position S in increasing order of their labels.

// For unreachable nodes, print -1.

// Sample Input
// 1
// 4 4
// 1 2 24
// 1 4 20
// 3 1 3
// 4 3 12
// 1

// Sample Output
// 24 3 15

/*
1
94 95
1 19 56
2 57 41
3 1 32
4 1 36
5 1 24
6 19 16
7 19 25
8 76 6
9 76 23
10 19 25
11 76 64
12 19 6
13 76 12
14 76 18
15 76 47
16 1 53
17 19 36
18 19 25
19 38 55
20 1 1
21 76 57
22 1 44
23 57 19
24 38 15
25 1 16
26 19 37
27 76 22
28 57 54
29 19 47
30 76 15
31 57 5
32 19 13
33 19 65
34 1 19
35 19 17
36 38 12
37 1 5
38 19 23
39 76 33
40 38 19
41 19 4
42 76 32
43 57 27
44 57 18
45 1 13
46 19 40
47 1 62
48 76 46
49 1 18
50 19 4
51 1 58
52 1 9
53 19 5
54 57 63
55 76 29
56 1 28
57 38 26
58 19 47
59 57 43
60 76 37
61 76 14
62 1 40
63 76 27
64 1 28
65 76 32
66 1 47
67 38 21
68 76 58
69 38 10
70 38 46
71 57 59
72 1 7
73 38 55
74 57 51
75 38 45
76 77 9
77 76 46
78 38 43
79 1 61
80 57 43
81 1 2
82 19 64
83 1 9
84 1 14
85 57 49
86 57 22
87 19 12
88 76 55
89 76 26
90 1 36
91 1 63
92 57 51
93 19 7
94 1 24
55 76 9
85
*/
