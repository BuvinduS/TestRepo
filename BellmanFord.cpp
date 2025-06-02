#include <bits/stdc++.h>
using namespace std;

vector<int> distances; 
vector<tuple<int,int,int>> edges;

void BellmanFord(int start, int n){
    distances.assign(n+1, INT_MAX);
    distances[start] = 0;
    for(int j = 1; j < n; j++){
        for(auto e : edges){
            int a,b,w;
            tie(a,b,w) = e;
            if(distances[a] != INT_MAX) distances[b] = min(distances[b], distances[a] + w);
        }
    }
}

void display(const vector<int> &dist){
    for(int i = 1; i < dist.size(); i++){
        cout << dist[i] << " ";
    }
    cout << endl;
}

int main(){
    edges = {{1,2,5},{1,3,3},{3,4,1},{4,5,2},{2,5,2},{2,4,3},{1,4,7}};
    int n = 5;
    BellmanFord(1,n);
    display(distances);
    return 0;
}