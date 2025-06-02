#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> generatePerms(vector<int> arr){
    sort(arr.begin(),arr.end());
    vector<vector<int>> allPerms;
    do{
        allPerms.push_back(arr);
    }while(next_permutation(arr.begin(),arr.end()));

    return allPerms;
}

void printPerms(const vector<vector<int>> &permVec){
    for(auto &i : permVec){
        cout << "{";
        for(int j = 0; j < i.size(); j++){
            if(j == i.size() - 1){cout << i[j];}
            else{cout << i[j] << ",";}    
        }
        cout << "}";
        cout << endl;
    }
}

int main(){
    vector<int> arr = {2,0,1};
    vector<vector<int>> allPerms = generatePerms(arr);
    printPerms(allPerms);
    return 0;
}