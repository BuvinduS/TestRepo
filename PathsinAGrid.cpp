#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> sumArr;
vector<vector<int>> values;
int n, m; int maiSum = 0;

void sum(int x, int y){
    sumArr[0][0] = values[0][0];
    // Find values for first row 
    for(int i = 1; i < x; ++i){
        sumArr[i][0] = sumArr[i-1][0] + values[i][0];
    }
    // Find values for first column 
    for(int i = 1; i < y; ++i){
        sumArr[0][i] = sumArr[0][i-1] + values[0][i];
    }
    // Fill the rest of the grid
    for(int i = 1; i < x; ++i){
        for(int j = 1; j < y; ++j){
            sumArr[i][j] = max(sumArr[i-1][j], sumArr[i][j-1]) + values[i][j];
        }
    }
}

void displayGrid(const vector<vector<int>> &grid){
    for(auto i : grid){
        for(auto j : i){
            cout << j << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main(){
    values = {{3,7,9,2,7},{9,8,3,5,5},{1,7,9,8,5},{3,8,6,4,10},{6,3,9,7,8}};
    n = values.size(); m = values[0].size();
    sumArr = vector<vector<int>>(n, vector<int>(m,0));
    sum(n,m);
    cout << "Largest path to the position [" << n << "][" << m << "] is " <<sumArr[n-1][m-1] << endl;

    displayGrid(sumArr);

    return 0;
}