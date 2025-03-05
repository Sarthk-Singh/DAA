#include <iostream>
#include <vector>
using namespace std;

void insertionSort(vector<int>& arr, int& comparisons, int& shifts) {
    int n = arr.size();
    comparisons = 0;
    shifts = 0;

    for (int i = 1; i < n; i++) {
        int temp = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > temp) {
            comparisons++;
            arr[j + 1] = arr[j];  
            shifts++;
            j--;
        }
        arr[j + 1] = temp;  
        shifts++;
    }
}

int main() {
    int T;
    cout << "Enter number of test cases: ";
    cin >> T;

    vector<vector<int>> sortedArrays(T);  
    vector<int> comparisons(T, 0);  
    vector<int> shifts(T, 0);  

    for (int i = 0; i < T; i++) {
        int n;
        cout << endl << "Enter size of array: ";
        cin >> n;

        vector<int> arr(n);
        cout << "Enter elements in the array: ";
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        insertionSort(arr, comparisons[i], shifts[i]);
        sortedArrays[i] = arr;
    }
    cout << endl << "Output:" << endl;
    for (int t = 0; t < T; t++) {
        cout << "Test Case " << t + 1 << ":" << endl;
        cout << "Sorted Array: ";
        for (int num : sortedArrays[t]) {
            cout << num << " ";
        }
        cout << endl << "Comparisons: " << comparisons[t];
        cout << endl << "Shifts: " << shifts[t] << endl;
    }
    return 0;
}
