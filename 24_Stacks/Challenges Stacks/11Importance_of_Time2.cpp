//Importance of Time

#include <iostream>
#include <deque>
using namespace std;

int main()
{
    long int N;
    cin >> N;
    deque<int> call;
    deque<int> ideal;
    for (int i = 0; i < N; i++)
    {
        int x;
        cin >> x;
        call.push_back(x);
    }
    for (int i = 0; i < N; i++)
    {
        int x;
        cin >> x;
        ideal.push_back(x);
    }
    int time = 0;
    for (int i = 0; i < N; i++)
    {
        if (call.front() == ideal.front())
        {
            time++;
            call.pop_front();
            ideal.pop_front();
        }
        else
        {
            while (call.front() != ideal.front())
            {
                int x = call.front();
                call.pop_front();
                call.push_back(x);
                time++;
            }
            call.pop_front();
            ideal.pop_front();
            time++;
        }
    }
    cout << time;
    return 0;
}