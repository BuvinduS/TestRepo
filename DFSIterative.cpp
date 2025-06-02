#include <bits/stdc++.h>
using namespace std;

vector<bool> visited;
vector<vector<int>> adj;

void DFS_iter(int start){
    stack<int> nodeStack;
    nodeStack.push(start);

    while(!nodeStack.empty()){
        // Get the node at the top of the stack and then remove it
        int node = nodeStack.top(); nodeStack.pop();
        if(visited[node]) continue;
        visited[node] = true;
        cout << "Visited node: " << node << endl;
        reverse(adj[node].begin(), adj[node].end());  // Optional: Only there to make sure the output is the same as the recursive version
        for(int i : adj[node]){
            if(!visited[i]) nodeStack.push(i);
        }
    }
}

int main(){
    adj = {{},{4,2},{1,3,5},{2,5},{1},{2,3}};  // The first entry is a dummy entry to compensate for the 1-indexed graph
    visited.assign(adj.size(), false);
    DFS_iter(1);
    return 0;
}