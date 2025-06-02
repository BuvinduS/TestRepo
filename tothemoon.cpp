#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'journeyToMoon' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. 2D_INTEGER_ARRAY astronaut
 */
vector<vector<int>> createAdj(vector<vector<int>> astronauts, int n){
    vector<vector<int>> adj(n);
    for(const auto &i : astronauts){
        adj[i[0]].push_back(i[1]);
        adj[i[1]].push_back(i[0]);
    }
    return adj;
}
vector<vector<int>> separateByCntry(vector<vector<int>> adj,int n){
    // Perform DFS to find connections
    vector<bool> visited(n,false);
    vector<vector<int>> countries;
    
    for(int i = 0; i < n; i++){
        if(visited[i]) continue;
        
        // Implement DFS using a stack
        stack<int> s;
        s.push(i); visited[i] = true;
        vector<int> belongsToCntry;
        while(!s.empty()){
            int country = s.top(); s.pop();
            belongsToCntry.push_back(country);
            // Process the adj list of the country
            for(auto c : adj[country]){
                if(visited[c]) continue;
                visited[c] = true;
                s.push(c);
            }
        }
        countries.push_back(belongsToCntry);
    }
    return countries;
}
void display(vector<vector<int>> countries){
    for(auto c : countries){
        cout << "Country : ";
        for(auto i : c){
            cout << i << " ";
        }
        cout << endl;
    }
}

long long journeyToMoon(int n, vector<vector<int>> astronaut) {
    vector<vector<int>> adj = createAdj(astronaut, n);
    vector<vector<int>> countries = separateByCntry(adj, n);
    long long totalWays = 0; int size = countries.size();
    int remainingAstronauts = n;
    
    for(auto &country : countries){
        remainingAstronauts -= country.size();
        totalWays += country.size()*remainingAstronauts;
    }
    return totalWays;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int p = stoi(first_multiple_input[1]);

    vector<vector<int>> astronaut(p);

    for (int i = 0; i < p; i++) {
        astronaut[i].resize(2);

        string astronaut_row_temp_temp;
        getline(cin, astronaut_row_temp_temp);

        vector<string> astronaut_row_temp = split(rtrim(astronaut_row_temp_temp));

        for (int j = 0; j < 2; j++) {
            int astronaut_row_item = stoi(astronaut_row_temp[j]);

            astronaut[i][j] = astronaut_row_item;
        }
    }

    long long result = journeyToMoon(n, astronaut);

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
