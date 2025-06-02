#include <bits/stdc++.h>
using namespace std;

vector<bool> processed;
vector<int> dist;
vector<vector<pair<int,int>>> adj;

void dijkstras(int start, int n){
    dist.assign(n+1, INT_MAX); processed.assign(n+1, false);

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;   //distance, node
    dist[start] = 0;
    pq.push(make_pair(0, start));

    while(!pq.empty()){
        int a = pq.top().second; pq.pop();
        if(processed[a]) continue;
        processed[a] = true;
        for(pair<int,int> i : adj[a]){
            int b = i.second; int w = i.first;
            if(dist[b] > dist[a] + w) dist[b] = dist[a] + w;
            pq.push(make_pair(dist[b],b));
        }
    }
}

void display(const vector<int> &dist){
    for(int i = 1; i < dist.size(); i++){
        cout << "Shorted path to node " << i << " is " << dist[i] << endl;
    }
    cout << endl;
}

int main(){
    int n = 5;
    adj.resize(n+1);

    adj[1] = {{9,4},{5,2},{1,5}};
    adj[2] = {{2,3}, {5,1}};
    adj[3] = {{2,2},{6,4}};
    adj[4] = {{6,3},{2,5},{9,1}};
    adj[5] = {{2,4},{1,1}};

    dijkstras(1,n); 
    display(dist);
    return 0;
}