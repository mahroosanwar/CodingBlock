#include <bits/stdc++.h>
using namespace std;

template <typename T>
class graph
{
    int v;
    map<T, list<T>> m;

public:
    graph(int v)
    {
        this->v = v;
    }
    void addedge(int x, int y)
    {
        m[x].push_back(y);
        //  m[y].push_back(x);
    }

    void bfsshortest(T src, T dest)
    {

        map<T, int> dist;
        bool visited[v];
        for (auto p : m)
        {
            dist[p.first] = -1;
            visited[p.first] = false;
        }

        queue<T> q;
        q.push(src);
        dist[src] = 0;
        visited[src] = true;
        while (!q.empty())
        {

            T node = q.front();

            q.pop();
            visited[node] = true; // no need
            for (auto p : m[node])
            {
                if (!visited[p])
                {
                    q.push(p);
                    dist[p] = dist[node] + 1;
                    visited[p] = true;
                }
            }
        }

        cout << dist[dest] << endl; // print the dist
    }
};
int main()
{

    int t;
    cin >> t;

    while (t--)
    {
        int n, l, s;
        cin >> n >> l >> s;
        graph<int> g(n);
        int board[n] = {0};

        for (int i = 0; i < l; i++)
        { // store all jumps
            int x, y;
            cin >> x >> y;
            int jump = y - x;
            board[x] = jump;
        }
        for (int i = 0; i < s; i++)
        { // store all ditches
            int x, y;
            cin >> x >> y;
            int ditch = y - x;
            board[x] = ditch;
        }

        // add all edges to graph
        for (int i = 0; i <= n; i++)
        {
            for (int dice = 1; dice <= 6; dice++)
            {
                int j = i + dice;
                j += board[i];

                if (j <= n * n)
                { // till edge is less than equal to n*n
                    g.addedge(i, j);
                }
            }
        }

        g.addedge(n, n); // finally add an edge from n to n
        g.bfsshortest(0, n);
    }

    return 0;
}