#include <bits/stdc++.h>
using namespace std;

vector<bool> visited;
vector<int> distances;
vector<vector<int>> adj;

void BFS(int start){
    queue<int> nodeQueue;
    visited[start] = true;
    distances[start] = 0;
    nodeQueue.push(start);

    while(!nodeQueue.empty()){
        int node = nodeQueue.front();
        nodeQueue.pop();

        for(int n : adj[node]){
            if(visited[n]) continue;
            visited[n] = true;
            distances[n] = 1 + distances[node];
            cout << "Distance to node " << n << " from node " << start << " is " << distances[n] << endl;
            nodeQueue.push(n);
        }
    }
}

int main(){
    adj = {{},{4,2},{1,3,5},{2,6},{1},{2,6},{3,5}};  // The first entry is a dummy entry to compensate for the 1-indexed graph
    visited.assign(adj.size(), false);
    distances.assign(adj.size(), 0);
    BFS(1);
    return 0;
}