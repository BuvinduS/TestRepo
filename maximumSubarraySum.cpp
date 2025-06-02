#include <bits/stdc++.h>
using namespace std;

//Kadane's Algorithm
int calMax(const vector<int> &arr){
    int best = 0, sum = 0;
    for(int i = 0; i < arr.size(); i++){
        sum = max(arr[i], sum+arr[i]);
        best = max(best,sum);
    }
    return best;
}

int main(){
    vector<int> arr = {-1,2,4,-3,5,2,-5,2};
    cout << calMax(arr) << endl;
    return 0;
}