#include <bits/stdc++.h>
using namespace std;

vector<bool> visited;
vector<vector<int>> adj; 

void DFS(int node){
    visited[node] = true;
    cout << "visited node : " << node << endl;
    for(int i : adj[node]){
        if(!visited[i]){
            DFS(i);
        }
    }
}

int main(){
    adj = {{},{4,2},{1,3,5},{2,5},{1},{2,3}};  // The first entry is a dummy entry to compensate for the 1-indexed graph
    visited.assign(adj.size(), false);
    DFS(1);
    return 0;
}