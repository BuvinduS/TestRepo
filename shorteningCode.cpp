#include <bits/stdc++.h>
using namespace std;

typedef long long ll;  //We have defined ll as the much shorter name that will be used to create long long type variables
typedef vector<int> vi; //int vector can now be accessed using vi
typedef pair<int,int> pi; //int,int pair can now be accessed using p1
int main(){
    ll a = 123456789;
    ll b = 987654321;
    cout << a*b << "\n";

    pi p(2,3);
    vi v = {3,2,1};

    cout << p.first << " " << p.second << endl;
    for(int i : v){cout << i << " ";}
    return 0;
}

