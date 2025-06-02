#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> getLongestSubSeq(const vector<int> &arr){
    vector<vector<int>> seqs;
    int n = arr.size();
    vector<int> lengths(n,1), prev(n,-1);
    int lastIndex = 0;

    for(int k = 1; k < n; ++k){
        for(int i = 0; i < k; ++i){
            if(arr[i] < arr[k] && lengths[k] < lengths[i] + 1){
                lengths[k] = lengths[i] + 1;
                prev[k] = i;
            }
        }
        // Reconstruct the longest Increasing Subsequence
        vector<int> lis;
        for(int j = k; j != -1; j = prev[j]){
            lis.push_back(arr[j]);
        }
        reverse(lis.begin(), lis.end());
        seqs.push_back(lis);
    }
    return seqs;
}

void display(const vector<vector<int>> &arr){
    for(auto i : arr){
        cout << "{ ";
        for(int j : i){
            cout << j << " ";
        }
        cout << "}";
        cout << endl;
    }
    cout << endl;
}

int main(){
    vector<int> arr = {6,2,5,1,7,4,8,3};
    vector<vector<int>> seqs = getLongestSubSeq(arr);
    display(seqs);
    return 0;
}