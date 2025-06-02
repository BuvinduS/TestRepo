#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> columns;
vector<int> mainDiag;
vector<int> seconDiag;
int solutionCount = 0;

void nQueens(int y){
    if(y == n){
        solutionCount++;
        return;
    }

    for(int x = 0; x < n; x++){
        if(columns[x] || mainDiag[x + y] || seconDiag[x - y + n - 1]){
            continue;
        }
        columns[x] = mainDiag[x + y] = seconDiag[x - y + n - 1] = 1;
        nQueens(y+1);
        columns[x] = mainDiag[x + y] = seconDiag[x - y + n - 1] = 0;
    }
}

int main(){
    cout << "Enter number of queens: " << endl;
    cin >> n;

    columns.resize(n);
    mainDiag.resize(2*n - 1);
    seconDiag.resize(2*n - 1);

    nQueens(0);

    cout << "Number of possibilities: " << solutionCount << endl;
    return 0;
}