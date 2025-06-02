#include <bits\stdc++.h>
using namespace std;

// Solving the coin change problem more efficently using memoization.
int memoHelper(int target, const vector<int> &coins, vector<bool> &ready, vector<int> &value){
    if(target < 0){
        return INT_MAX;
    }
    if(target == 0){
        return 0;
    }
    if(ready[target]) return value[target];
    int best = INT_MAX;
    for(int c : coins){
        int res = memoHelper(target - c, coins, ready, value);
        if(res != INT_MAX){
            best = min(best, res + 1);   // the +1 accounts for the current coin that was just used
        }
    }

    value[target] = best;
    ready[target] = true;
    return best;
}


int solve(int target, const vector<int> &coins){
    // Assume the maximum target required is 100 
    vector<int> value(100);
    vector<bool> ready(100);

    int val = memoHelper(target, coins, ready, value);

    return val;
}

int main(){
    vector<int> coins = {1,2,3};
    int target = 4;
    int best = solve(target, coins);
    cout << "The number of coins required for the optimal solution is: " << best << endl;
    return 0;
}