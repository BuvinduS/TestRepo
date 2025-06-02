#include<bits/stdc++.h>
using namespace std;

// Bottom-up approach using iteration

const int INF = INT_MAX;
vector<int> value;

int solve(int target, const vector<int> &coins){
    value[0] = 0;
    for(int x = 1; x <= target; x++){
        for(int c : coins){
            if(x - c >= 0 && value[x-c] != INF){
                value[x] = min(value[x], value[x-c] + 1);
            }
        }
    }
    return value[target];
}
int main(){
    vector<int> coins = {1,2,3};
    int target = 4;

    value.resize(target + 1,INF); 

    int best = solve(target, coins);
    cout << "Using bottom-up iternation method: " << endl;
    cout << "The number of coins required for the optimal solution is: " << best << endl;
    return 0;
}