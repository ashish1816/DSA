// Online C++ compiler to run C++ program online

/*
Input:-
6 9
1 2 4
1 6 2
2 3 5 
2 6 1
6 3 8
6 5 10
3 4 6
3 5 3
5 4 5

Output:-
0 3 8 14 11 2 
*/
#include <iostream>
#include  <vector>
#include <climits>
#include <utility>
#include <queue>

using namespace std;

vector<pair<int, int> > adj[1001];

int main() {
    // Write C++ code here
    int n, m, a, b, w;
    cin >> n >> m;  // nodes and edges
    
    while(m--) {
        cin >> a >> b >> w;
        adj[a].push_back({b, w});
        adj[b].push_back({a, w});
    }
    
    // pq -> {dist_from_source_node, node}
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int>> > pq;
    
    vector<int> dist(n+1, INT_MAX);
    // source node is 1 and it's distance is 0
    pq.push({0, 1});
    dist[1] = 0;
    
    while(!pq.empty()) {
        int curr = pq.top().second;
        int curr_d = pq.top().first;
        pq.pop();
        
        for(pair<int, int> edge: adj[curr]) {
            if(curr_d + edge.second < dist[edge.first]) {
                dist[edge.first] = curr_d + edge.second;
                pq.push({dist[edge.first], edge.first});
            }
        }
    }
    
    for(int i=1; i<=n; i++) {
        cout << dist[i] << " ";
    }
    
    return 0;
}