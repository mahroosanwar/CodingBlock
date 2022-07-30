#include <bits/stdc++.h>

using namespace std;

void dijkstra(map<int, list<pair<int, int>>> m, int src, int n)
{
    map<int, int> distance;
    for (auto p : m)
    {
        int node = p.first;
        distance[node] = INT_MAX;
    }
    distance[src] = 0;
    set<pair<int, int>> s;
    s.insert(make_pair(0, src));

    while (!s.empty())
    {
        auto pair = *(s.begin());
        s.erase(s.begin());
        int edgedist = pair.first;
        int vertex = pair.second;

        for (auto nbr : m[vertex])
        {
            if (edgedist + nbr.second < distance[nbr.first])
            {

                int destination = nbr.first;
                auto pp = s.find(make_pair(distance[destination], destination));
                if (pp != s.end())
                {
                    s.erase(pp);
                }

                distance[destination] = edgedist + nbr.second;
                s.insert(make_pair(distance[destination], destination));
            }
        }
    }
    for (auto p : distance)
    {
        int node = p.first;
        if (p.second == INT_MAX)
        {
            distance[node] = -1;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if (i == src)
            continue; // dont print src
        cout << distance[i] << " ";
    }
}

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n, m1;
        cin >> n >> m1;
        map<int, list<pair<int, int>>> m;
        for (int j = 0; j < m1; j++)
        {
            int x, y, r;
            cin >> x >> y >> r;
            m[x].push_back(make_pair(y, r));
            m[y].push_back(make_pair(x, r));
        }
        int src;
        cin >> src;
        dijkstra(m, src, n);
        cout << endl;
    }

    return 0;
}
