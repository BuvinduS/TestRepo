#include <bits/stdc++.h>
using namespace std;

bool strComp(string a, string b){
    // Returns true if 'a' should come before 'b':
    // shorter strings first; if equal length, then lexicographically smaller
    if(a.size() != b.size()) return a.size() < b.size();
    return a < b;
}

int main(){
    vector<string> arr = {"abc","def", "alk","xyz","xsedf"};
    for(const string &s : arr){cout << s << " ";}

    sort(arr.begin(), arr.end(),strComp);

    for(const string &s : arr){cout << s << " ";}
    return 0;
}