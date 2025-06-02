#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> generateSubsets(vector<int> &arr){
    vector<vector<int>> allSubSets;
    int n = arr.size();
    for(int b = 0; b < (1 << n); b++){
        vector<int> sub;
        for(int i = 0; i < n; i++){
            if(b & (1 << i)){
                sub.push_back(arr[i]);
            }
        }
        allSubSets.push_back(sub);
    }

    return allSubSets;
}

bool isPossible(vector<int> &arr, int target){
    vector<int> firstHalf;
    vector<int> secondHalf;
    int n = arr.size()/2;

    firstHalf.insert(firstHalf.begin(), arr.begin(), arr.begin() + n);
    secondHalf.insert(secondHalf.begin(), arr.begin() + n, arr.end());

    vector<vector<int>> firstSetSubs = generateSubsets(firstHalf);
    vector<vector<int>> secondSetSubs = generateSubsets(secondHalf);

    for(auto i : firstSetSubs){
        int sum = accumulate(i.begin(), i.end(), 0);
        for(auto j : secondSetSubs){
            if(sum + accumulate(j.begin(),j.end(),0) == target){
                return true;
            }
        }
    }
    return false;
}

int main(){
    vector<int> arr = {2,4,5,9};
    int target = 9;

    if(isPossible(arr,target)){
        cout << "Possible" << endl;
    }else{
        cout << "Not Possible" << endl;
    }

    return 0;
}