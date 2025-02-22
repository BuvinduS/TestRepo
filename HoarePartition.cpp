// Attempt at recursive quick sort
# include <iostream>
# include <vector>
using namespace std;
// C++ program to partition the array
// using Hoare's Partition Algorithm

int HoarePartition(vector<int> &arr,int low, int high){
    int pivot = arr[low];

    int i = low - 1; int j = high+1;

    while(true){
        do{
            i++;
        }while(arr[i] < pivot);

        do{
            j--;
        }while(arr[j] > pivot);

        if (i >= j){
            return j;
        }else{
            swap(arr[i], arr[j]);
        }
    }
}

void quickSort(vector<int> &arr, int low, int high){
    if (low < high) {
        int i = HoarePartition(arr, low, high);
        quickSort(arr, low, i);
        quickSort(arr, i + 1, high);
    }
}


int main(){
    vector<int> arr = {7,9,11,6,2,8,5,-5,21,4,89,1,3,4,78};
    int pivotIndex = HoarePartition(arr, 0, arr.size()-1);

    quickSort(arr, 0, arr.size()-1);

    for(int i : arr){
        cout << i << " ";
    }
    cout << endl;
    cout << pivotIndex << endl;
}