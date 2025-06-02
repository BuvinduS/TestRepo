#include<bits/stdc++.h>
using namespace std;

struct P{
    int x,y;
    bool operator<(const P &p){
        if (x != p.x){return x < p.x;}
        else{return y < p.y;}
    }
};

int main(){
    P p1{2,4};
    P p2{3,5};
    P p3{2,8};

    cout << (p1 < p2) << " " << (p2 < p3) << " " << (p1 < p3);
    return 0;
}