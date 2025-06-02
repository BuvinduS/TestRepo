#include <bits/stdc++.h>
using namespace std;

/*
    Greedy Algorithm
    Only works if the coin system is canonical i. e. like {1,2,5,10,20,50,100,200}
    For systems like {1,3,4} this might fail
*/

vector<int> coinProb(vector<int> &coins, int target){
    if(!is_sorted(coins.begin(),coins.end())){
        sort(coins.begin(),coins.end());
    }
    vector<int> sol;
    for(int i = coins.size() - 1; i >= 0; i--){
        while(target >= coins[i]){
            target -= coins[i];
            sol.push_back(coins[i]);
        }
        if(target == 0){
            return sol;
        }
    }
    return {};
}

void display(const vector<int>&arr){
    for(int i : arr){
        cout << i << " ";
    }
    cout << endl;
}

int main(){
    vector<int> coins = {1,2,5,10,20,50,100,200};
    int target = 520;
    display(coinProb(coins,target));
    return 0;
}