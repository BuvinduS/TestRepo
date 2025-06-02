#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> createSubsets(const vector<int> &arr, int n){
    vector<vector<int>> allSubsets;
    for(int b = 0; b < (1 << n); b++){
        vector<int> subSet;
        for(int i = 0; i < n; i++){
            if(b & (1 << i)){
                subSet.push_back(arr[i]);
            }
        }
        allSubsets.push_back(subSet);
    }
    return allSubsets;
}

void printSubsets(const vector<vector<int>> &subsetVec){
    for(auto i : subsetVec){
        cout << "{";
        for(int j : i){
            if(j == *prev(i.end())){cout << j;}
            else{cout << j << ",";}
        }
        cout << "}";
        cout << endl;
    }
}

int main(){
    vector<int> arr = {0,1,2};
    vector<vector<int>> subsetVec = createSubsets(arr, arr.size());
    printSubsets(subsetVec);
    return 0;
}