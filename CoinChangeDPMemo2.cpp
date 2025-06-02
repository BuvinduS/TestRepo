#include <bits/stdc++.h>
using namespace std;

const int INF = INT_MAX;
vector<bool> ready;
vector<int> value;

int solve(int target, const vector<int> &coins){
    if(target < 0) return INF;
    if(target == 0) return 0;
    if(ready[target]) return value[target];

    int best = INF;
    for(const int &c : coins){
        int res = solve(target - c, coins);
        if(res != INF) best = min(best, res + 1);
    }

    ready[target] = true;
    value[target] = best;
    return best;
}

int main(){
    vector<int> coins = {1,2,3};
    int target = 4;

    ready.resize(target + 1, false);
    value.resize(target + 1, INF);

    int best = solve(target, coins);
    cout << "The number of coins required for the optimal solution is: " << best << endl;
    return 0;
}