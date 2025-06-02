// DOES NOT WORK!!!!!

#include <bits/stdc++.h>
using namespace std;
int main(){
    vector<int> a = {1,3,5,7,9};
    int target = 6;

    auto ok = [&](int i){
        return i >= 0 && i < a.size() && a[i] >= target;
    };

 
    int x = -1;
    for(int b = 1 << 20; b >= 1; b /= 2){   //Mathematically 1 << n is the same as 2^n
        while(!ok(x + b)){
            x += b;
        }
    }
    int k = x + 1;

    cout << "First index with a[i] >= target: " << k << "\n";
    return 0;
}