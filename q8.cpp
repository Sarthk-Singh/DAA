#include <iostream>
#include <vector>
using namespace std;

void selectionSort(vector<int>& arr, int& comparisons, int& swaps) {
    int n = arr.size();
    comparisons = 0;
    swaps = 0;

    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            comparisons++;
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            swap(arr[i], arr[minIndex]);
            swaps++;
        }
    }
}

int main() {
    int T;
    cout << "Enter number of test cases: ";
    cin >> T;

    vector<vector<int>> sortedArrays(T);  
    vector<int> comparisons(T, 0);  
    vector<int> swaps(T, 0);  

    for (int t = 0; t < T; t++) {
        int n;
        cout << endl << "Enter size of array: ";
        cin >> n;

        vector<int> arr(n);
        cout << "Enter elements in the array: ";
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        
        selectionSort(arr, comparisons[t], swaps[t]);
        sortedArrays[t] = arr;
    }

    
    cout << endl << "Output:" << endl;
    for (int t = 0; t < T; t++) {
        cout << "Test Case " << t + 1 << ":" << endl;
        cout << "Sorted Array: ";
        for (int num : sortedArrays[t]) {
            cout << num << " ";
        }
        cout << endl << "Comparisons: " << comparisons[t];
        cout << endl << "Swaps: " << swaps[t] << endl;
    }

    return 0;
}

