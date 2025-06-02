#include<bits/stdc++.h>
using namespace std;

// Bottom-up approach using iteration

const int INF = INT_MAX;
vector<int> value, lastCoinUsed;

int solve(int target, const vector<int> &coins){
    value[0] = 0;
    for(int x = 1; x <= target; x++){
        for(int c : coins){
            if(x - c >= 0 && value[x-c] != INF){
                if(value[x] > value[x - c] + 1){
                    value[x] = value[x - c] + 1;
                    lastCoinUsed[x] = c; // Each time value[x] is updated the coin that gave the improvement is recorded
                }
            }
        }
    }
    return value[target];
}

void getCoinCombination(int target){
    if(value[target] == INF){
        cout << "No valid combination present." << endl;
        return;
    }
    cout << "Coins used: ";
    while(target > 0){
        int coin = lastCoinUsed[target];
        cout << coin << " ";
        target -= coin;
    }
    cout << endl;
}

int main(){
    vector<int> coins = {1,2,3};
    int target = 10;

    value.resize(target + 1,INF);
    lastCoinUsed.resize(target + 1,0);

    int best = solve(target, coins);
    cout << "Using bottom-up iternation method: " << endl;
    cout << "The number of coins required for the optimal solution is: " << best << endl;

    getCoinCombination(target);
    return 0;
}