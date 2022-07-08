//Expedition Code (Hard)

#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;


bool compare(pair<int, int> p1, pair<int, int> p2) {
    //compare two fuel station based upon their distance from the town,
    //one with the smaller distance from the town will be the bigger one
    return p1.first > p2.first;
}

int main() {

    int n, t, x, d, f, D, F, prev=0;
    cin >> t;

    while(t--) {

        int flag = 0, ans = 0;
        //vector to stroe the fuel station and their capacity
        vector<pair<int, int> > v;

        //priority queue to store the capicity of fule station
        priority_queue<int> pq;

        cin >> n;   //no. of stop

        for(int i=0; i<n; i++) {
            //Distance and Fuel
            cin >> d >> f;
            v.push_back(make_pair(d, f));
        }

        //logic
        //sort the cities according to their location
        sort(v.begin(), v.end(), compare);

        //initial distance and capacity of truck
        cin >> D >> F;

        //update the distance fule station form the truck
        for(int i=0; i<n; i++) {
            v[i].first = D - v[i].first;
        }

        //prev denotes the previous city we have visited 
        prev = 0;
        x = 0;  //current city

        // component 1: Visit all the fuel station (have two cases)
        while(x<n) {
            // case 1:
            //if we have enough fuel to go to next city(i.e. fuel station)
            if(F >= (v[x].first - prev)) {
                
                F = F - (v[x].first - prev);    //reduce the capicity of truck by this amount
                pq.push(v[x].second);       //since we reach the next fuelling station, add to priority queue 
                prev = v[x].first;      //update the previous
            }
            
            //case 2:
            //if we cann't reach the next station form current capacity
            else {
                //check if some fulling station visited in pq
                if(pq.empty()) {
                    flag = 1;
                    break;
                }

                //otherwise refuel the truck with fuelling station with higher capacity
                F += pq.top();
                //remove that fuel station form pq;
                pq.pop();
                ans = ans + 1;
                continue;
            }

            x++;    //increment the city you have visited 
        }

        // component 2: if u want to travel from the last fuelling to the town
        //actually travelled through n fuel station
        //what is left you have reach the town from the last fuel station 

        if(flag == 1) {
            cout << -1 << endl;
            continue;
        } 

        //otherwise
        D = D - v[n-1].first;
        if(F>=D) {
            cout << ans << endl;
            continue;
        }

        //othewise
        //if u have enough fuel to reach then u reach town otherwise u won't be able to reach
        while(F<D) {
            if(pq.empty()) {
                flag = 1;
                break;
            }

            F += pq.top();
            pq.pop();
            ans = ans + 1;
        }

        if(flag == 1) {
            cout << -1 << endl;
            continue;
        }
        cout << ans << endl;
    }
    return 0;
}