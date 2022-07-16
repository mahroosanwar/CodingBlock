//Expedi

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

bool cmp(pair<int, int> p1, pair<int, int> p2)
{
    return p1.first > p2.first;
}

int main()
{
    int flag = 0;
    int ans = 0;

    vector<pair<int, int>> v;
    priority_queue<int> pq;

    int n, d, f, D, F;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> d >> f;
        v.push_back(make_pair(d, f));
    }

    sort(v.begin(), v.end(), cmp);

    cin >> D >> F;

    for (int i = 0; i < n; i++)
    {
        v[i].first = D - v[i].first;
    }

    int x = 0;
    int prev = 0;

    while (x < n)
    {
        if (F >= v[x].first - prev)
        {
            F = F - (v[x].first - prev);
            pq.push(v[x].second);
            prev = v[x].first;
        }
        else
        {
            if (pq.empty())
            {
                flag = 1;
                break;
            }
            F += pq.top();
            pq.pop();
            ans++;
            continue;
        }
        x++;
    }

    if (flag == 1)
    {
        cout << "-1" << endl;
    }
    else
    {

        D = D - v[n - 1].first;
        if (F >= D)
        {
            cout << ans << endl;
        }
        else
        {
            while (F < D)
            {
                if (pq.empty())
                {
                    flag = 1;
                    break;
                }
                F = F + pq.top();
                pq.pop();
                ans++;
            }

            if (flag == 1)
            {
                cout << "-1" << endl;
            }

            cout << ans << endl;
        }
    }
    return 0;
}

// A group of cows grabbed a truck and ventured on an expedition deep into the jungle. Being rather poor drivers, the cows unfortunately managed to run over a rock and puncture the truck's fuel tank. The truck now leaks one unit of fuel every unit of distance it travels.

// To repair the truck, the cows need to drive to the nearest town (no more than 1,000,000 units distant) down a long, winding road. On this road, between the town and the current location of the truck, there are N (1 <= N <= 10,000) fuel stops where the cows can stop to acquire additional fuel (1..100 units at each stop).

// The jungle is a dangerous place for humans and is especially dangerous for cows. Therefore, the cows want to make the minimum possible number of stops for fuel on the way to the town. Fortunately, the capacity of the fuel tank on their truck is so large that there is effectively no limit to the amount of fuel it can hold. The truck is currently L units away from the town and has P units of fuel (1 <= P <= 1,000,000).

// Determine the minimum number of stops needed to reach the town, or if the cows cannot reach the town at all.

// Input Format
// The First Line contains a N integer followed by N number of pairs in the next lines.
// Each line contains two space-separated integers describing a fuel stop: The first integer is the distance from the town to the stop; the second is the amount of fuel available at that stop.
// The Last line contains a pair of L and P.

// Constraints
// 1 <= N <= 10,000

// 1 <= P <= 1,000,000

// Output Format
// Output single integer denoting the minimum number of stops.

// Sample Input
// 4
// 4 4
// 5 2
// 11 5
// 15 10
// 25 10
// Sample Output
// 2