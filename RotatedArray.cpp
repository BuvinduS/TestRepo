#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
using namespace std;

vector<int> getInput(){
    string inputLine;
    getline(cin, inputLine);
    istringstream iss(inputLine);
    string token;
    vector<int> arr;
    while(getline(iss,token,',')){
        arr.push_back(stoi(token));
    }
    
    return arr;
}

int main() {
    vector<int> arr = getInput();
    int pivot;
    cin >> pivot;
    auto it = find(arr.begin(),arr.end(),pivot);
    if(it!=arr.end()){
        int index = distance(arr.begin(), it);
        cout << index << endl;
    }else{
        cout << -1 << endl;
    }
    return 0;
}
