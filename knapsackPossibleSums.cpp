#include <bits/stdc++.h>
using namespace std;

vector<int> weights;
vector<bool> possible;

void knapsackSums(int k, int totalSum){
    possible[0] = true;
    for(int k = 0; k < weights.size(); k++){
        for(int x = totalSum; x >=0 ; x--){
            if(possible[x]){
                possible[x + weights[k]] = true;
            }
        }
    }
}

void display(const vector<bool> &arr){
    for(int i : arr){
        cout << i << " ";
    }
    cout << endl;
}

int main(){
    weights = {1,3,3,5};
    int totalSum = accumulate(weights.begin(), weights.end(), 0);
    possible.resize(totalSum + 1);
    knapsackSums(weights.size(),totalSum);
    display(possible);
    return 0;
}