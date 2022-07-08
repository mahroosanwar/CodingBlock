// Chopsticks

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int main() {
    ll n, d, a;
    vector<ll> v;
    cin >> n >> d;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        v.push_back(a);
    }

    // Sort the list of sticks
    sort(v.begin(), v.end());

    int res = 0;
    for (int i = 0; i < n - 1;)
    {

        // If the adjacent difference is less than d
        // we can make a pair
        // Now remove these two sticks from the list
        if (v[i + 1] - v[i] <= d)
        {
            res++;
            i += 2;
        }

        // If we cannot make a pair with adjacent stick
        // This stick is useless, remove this stick from the list

        else
            i++;
    }
    cout << res << endl;
    return 0;
}