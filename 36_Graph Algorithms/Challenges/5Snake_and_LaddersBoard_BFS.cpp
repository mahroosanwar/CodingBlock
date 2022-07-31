//Snake and Ladders Board (BFS)

#include<iostream>
#include<map>
#include<queue>
#include<list>
#include<climits>
using namespace std;

class Graph{
	map<int,list<int>> l;
	public:
	void addEdge(int x,int y){
		l[x].push_back(y);
	}

	void bfs(int src,int des){
		map<int,int> dist;
		queue<int> q;

		for(auto x: l){
			dist[x.first] = INT_MAX;
		}

		dist[src] = 0;
		q.push(src);

		while(!q.empty()){
			int node = q.front();
			q.pop();

			for(auto x:l[node]){
				if(dist[x] == INT_MAX){
					q.push(x);
					dist[x] = dist[node] + 1;
				}
			}
		}

		cout<<dist[des]<<endl;
	}
};

int main() {
	int t;
	cin>>t;
	while(t--){
		int n,l,s,start,end;
		cin>>n>>l>>s;
		int board[50] = {0};
		for(int i=0;i<l;i++){
			cin>>start>>end;
			int d = end - start;
			board[start] = d;
		}

		for(int i=0;i<s;i++){
			cin>>start>>end;
			int d = end - start;
			board[start] = d;
		}

		Graph G;
		for(int i=0;i<=n;i++){
			for(int dice=1;dice<=6;dice++){
				int j = i + dice;
				j += board[j];
				if(j<=n){
					G.addEdge(i,j);
				}
			}
		}
		G.addEdge(n,n);
		G.bfs(0,n);
	}
	return 0;
}

// Given a snake and ladder board, find the minimum number of dice throws required to reach the destination or last cell from source or 1st cell. The player has total control over outcome of dice throw and wants to find out minimum number of throws required to reach last cell.

// Input Format
// First line contains integer t as number of test cases.
// Each test case contains following input.
// First line contains three integers n, l, s which represents the number of cells of board, number of ladders and number of snakes.
// Next l lines contains two integers each x & y denoting there is a ladder from x to y.
// Next s lines contains two integers each x & y denoting there is a snake from x to y.



// Constraints
// 1 < t < 20 1< n,l,s < 50

// Output Format
// For each test case you have to print the number which is equal to the minimum number of dice throws to reach the last cell.

// Sample Input
// 1
// 30 4 4
// 3 22
// 5 8
// 11 26
// 20 29
// 17 4
// 19 7
// 21 9
// 27 1
// Sample Output
// 3
// Explanation
// Player start from the first cell. It goes to 1st 3 (then reach at 22) and then 28 and then 30. Total number of dice thrown is 3.