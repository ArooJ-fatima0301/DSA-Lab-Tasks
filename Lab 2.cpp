#include <iostream>
using namespace std;

int MaxValue(int arr[], int n){
    int max= arr[0];

    for(int i=0; i<n; i++){
        if(arr[i] > max){
            max = arr[i];
        }
    }

    return max;
}

int main(){

    /*
    Implement a function that finds the maximum value in an array of size n. Determine its time complexity
     and explain why it is O(n).
    */

    int arr[] = { 12, 0, -122, 35, 79, 334};

    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Array = {";
    for(int i=0; i<n; i++){
        cout << arr[i];
        if(i != n-1){
            cout << ", ";
        }
    }
    cout << "}\n\n";

    int maxValue = MaxValue(arr, n);

    cout << "Max Value in the Array = " << maxValue << "\n\n";

    return 0;
}