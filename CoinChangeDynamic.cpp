#include <bits\stdc++.h>
using namespace std;

int solve(int target, const vector<int> &coins){
    if(target < 0){
        return INT_MAX;
    }
    if(target == 0){
        return 0;
    }
    int best = INT_MAX;
    for(int c : coins){
        int res = solve(target - c, coins);
        if(res != INT_MAX){
            best = min(best, res + 1);   // the +1 accounts for the current coin that was just used
        }
    }
    return best;
}

int main(){
    vector<int> coins = {1,2,3};
    int target = 4;
    int best = solve(target, coins);
    cout << "The number of coins required for the optimal solution is: " << best << endl;
    return 0;
}