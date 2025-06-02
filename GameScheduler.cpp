#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <unordered_map>
using namespace std;

int minIntervals(vector<char> &arr, int n){
    unordered_map<char, int> freqMap;
    
    for(char c : arr){
        freqMap[c]++;
    }
    int maxFreq = 0; int maxCount = 0;
    
    for(auto &entry : freqMap){
        if(entry.second > maxFreq){
            maxFreq = entry.second;
            maxCount = 1;
        }else if(entry.second == maxFreq){
            maxCount++;
        }
    }
    
    int spaceCount = maxFreq - 1;
    int spaceSize = n - maxCount + 1;
    int emptySlots = spaceCount * spaceSize;
    int remainingTeams = arr.size() - (maxCount*maxFreq);
    int idleSlots = max(0, emptySlots - remainingTeams);
    
    return (arr.size() + idleSlots);
    
}

void display(const vector<char> &arr){
    for(char c : arr){
        cout << c << "_";
    }
    cout << endl;
    
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int n;
    string inputLine;
    getline(cin, inputLine);
    int lineSize = inputLine.size();
    vector<char> arr;
    for(int i = 0; i < lineSize; i++){
        if((inputLine[i] == '\"' || inputLine[i] == '\'') && i + 1 < lineSize){
            arr.push_back(inputLine[i+1]);
            i += 2;
        }
    }
    cin >> n;
    
    if(n == 1){
        cout << arr.size();
    }else{
        cout << minIntervals(arr, n) << endl;
    }
    return 0;
}
