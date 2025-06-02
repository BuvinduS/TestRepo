#include <bits/stdc++.h>
using namespace std;

vector<int> longestSubSeq(const vector<int> &arr){
    int n = arr.size();
    vector<int> lengths(n,1);

    lengths[0] = 1;
    for(int k = 1; k < n; k++){
        for(int i = 0; i < k; i++){
            if(arr[i] < arr[k]){
                lengths[k] = max(lengths[k],lengths[i] + 1);
            }
        }
    }
    return lengths;
}

void display(const vector<int> &arr){
    for(int i : arr){
        cout << i << " ";
    }
    cout << endl;
}

int main(){
    vector<int> arr = {6,2,5,1,7,4,8,3};
    vector<int> lengths = longestSubSeq(arr);
    display(lengths);
    return 0;
}