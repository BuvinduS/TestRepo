#include <bits/stdc++.h>
using namespace std;

int inBoth(vector<int> &a, vector<int> &b){
    unordered_set<int> mySet;
    mySet.insert(a.begin(), a.end());
    mySet.insert(b.begin(), b.end());
    int diff = a.size() + b.size() - mySet.size();
    return abs(diff);
}

int main(){
    vector<int> a = {5,2,8,9,4};
    vector<int> b = {3,2,9,5};
    cout << "No of elements in both is: " << inBoth(a,b) << endl;
    return 0;
}