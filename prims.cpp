#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'prims' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. 2D_INTEGER_ARRAY edges
 *  3. INTEGER start
 */
vector<vector<pair<int, int>>> createAdj(const vector<vector<int>> &edges, int n){
    vector<vector<pair<int, int>>> adj(n+1);
    adj[0] = {{-1,-1}}; // Not used
    for(auto i : edges){
        int start = i[0]; int end = i[1]; int weight = i[2];
        adj[start].push_back({end, weight});
        adj[end].push_back({start, weight});
    }
    return adj;
}


int prims(int n, vector<vector<int>> edges, int start) {
    int minW = 0;
    vector<vector<pair<int, int>>> adj = createAdj(edges, n);
    
    priority_queue<pair<int,int> , vector<pair<int,int>>, greater<>> pq;
    vector<bool> visited(n+1,false);
    
    pq.push({0,start});
    
    while(!pq.empty()){
        int weight = pq.top().first;
        int currNode = pq.top().second;
        pq.pop();
        
        if(visited[currNode]) continue;
        visited[currNode] = true;
        
        minW += weight;
        
        for(auto j : adj[currNode]){
            if(visited[j.first]) continue;
            pq.push({j.second, j.first});
        }
    }
    return minW;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int m = stoi(first_multiple_input[1]);

    vector<vector<int>> edges(m);

    for (int i = 0; i < m; i++) {
        edges[i].resize(3);

        string edges_row_temp_temp;
        getline(cin, edges_row_temp_temp);

        vector<string> edges_row_temp = split(rtrim(edges_row_temp_temp));

        for (int j = 0; j < 3; j++) {
            int edges_row_item = stoi(edges_row_temp[j]);

            edges[i][j] = edges_row_item;
        }
    }

    string start_temp;
    getline(cin, start_temp);

    int start = stoi(ltrim(rtrim(start_temp)));

    int result = prims(n, edges, start);

    fout << result << "\n";

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
