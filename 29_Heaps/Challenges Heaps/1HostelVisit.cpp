// Hostel Visit

#include <iostream>
#include <queue>
#include <math.h>
#define ll long long int
using namespace std;
int main()
{
    ll n, k;
    cin >> n >> k;
    priority_queue<ll> q;
    for (ll i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        if (x == 1)
        {
            ll a, b;
            cin >> a >> b;
            ll dis = a * a + b * b;
            if (q.size() < k)

                q.push(dis);
            else if (q.top() > dis)
            {

                q.pop();
                q.push(dis);
            }
        }
        else
        {
            cout << q.top() << endl;
        }
    }
    return 0;
}