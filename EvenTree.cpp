#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

int DFS(const vector<vector<int>> &adj, int start, int &count, vector<int> &visited){
    visited[start] = true;
    int subTreeSize = 1;
    
    for(int child : adj[start]){
        if(visited[child]) continue;
        int childSize = DFS(adj, child, count, visited);
        if(childSize % 2 == 0) count++;
        else subTreeSize += childSize;
    }
    return subTreeSize;
}

vector<vector<int>> createAdj(int t_nodes, const vector<int> &t_from, const vector<int> &t_to){
    vector<vector<int>> adj(t_nodes + 1);
    int n = t_from.size();
    for(int i = 0; i < n; ++i){
        adj[t_from[i]].push_back(t_to[i]);
        adj[t_to[i]].push_back(t_from[i]);
    }
    return adj;
}

// Complete the evenForest function below.
int evenForest(int t_nodes, int t_edges, vector<int> t_from, vector<int> t_to) {
    vector<vector<int>> adj = createAdj(t_nodes, t_from, t_to);
    int count = 0; int n = adj.size();
    vector<int> visited(n,false);
    
    DFS(adj, 1, count, visited);
    return count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_nodes_edges_temp;
    getline(cin, t_nodes_edges_temp);

    vector<string> t_nodes_edges = split(rtrim(t_nodes_edges_temp));

    int t_nodes = stoi(t_nodes_edges[0]);
    int t_edges = stoi(t_nodes_edges[1]);

    vector<int> t_from(t_edges);
    vector<int> t_to(t_edges);

    for (int i = 0; i < t_edges; i++) {
        string t_from_to_temp;
        getline(cin, t_from_to_temp);

        vector<string> t_from_to = split(rtrim(t_from_to_temp));

        int t_from_temp = stoi(t_from_to[0]);
        int t_to_temp = stoi(t_from_to[1]);

        t_from[i] = t_from_temp;
        t_to[i] = t_to_temp;
    }

    int res = evenForest(t_nodes, t_edges, t_from, t_to);

    fout << res << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
