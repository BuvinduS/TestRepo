#include <bits/stdc++.h>
using namespace std;

/*
Arithmetic progression
    ex : 3,7,11,15 ==> difference between any two consecutive numbers is constant
    if there are n numbers the sum can be obtained using
            a+.....+b = n(a+b)/2
*/

int arithmetic(const vector<int> arr){
    int n = arr.size();
    int a = arr.at(0);
    int b = arr.at(n-1);

    return n*(a+b)/2;
}

/*
Geometric Progression
    ex : 3,6,12,24
        if k is the common ratio between two numbers
            a + ak + ak^2 + .....+b = (bk - a)/(k - 1)
*/
int geometric(const vector<int> arr){
    int k = arr[1]/arr[0];
    int a = arr[0]; 
    int b = arr[arr.size()-1];

    return (b*k - a)/(k - 1);
}

int main(){
    vector<int> arithmeticV = {3,7,11,15};
    vector<int> geometricV = {3,6,12,24};
    cout << "Sum of the arithmetic progerssion is: " << arithmetic(arithmeticV) << endl;
    cout << "Sum of the geometric progerssion is: " << geometric(geometricV) << endl;

    return 0;
}

