#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &arr, int l, int mid, int h, int &comparisons, int &inversions)
{
    int left = l, right = mid + 1, k = 0;
    vector<int> temp(h - l + 1);
    while (left <= mid && right <= h)
    {
        comparisons++;
        if (arr[left] <= arr[right])
        {
            temp[k++] = arr[left++];
        }
        else
        {
            temp[k++] = arr[right++];
            inversions += (mid - left + 1);
        }
    }
    while (left <= mid)
        temp[k++] = arr[left++];
    while (right <= h)
        temp[k++] = arr[right++];
    for (int i = l, j = 0; i <= h; i++, j++)
    {
        arr[i] = temp[j];
    }
}
void mergeSort(vector<int> &arr, int l, int h, int &comparisons, int &inversions)
{
    if (l >= h)
        return;
    int mid = l + (h - l) / 2;
    mergeSort(arr, l, mid, comparisons, inversions);
    mergeSort(arr, mid + 1, h, comparisons, inversions);
    merge(arr, l, mid, h, comparisons, inversions);
}
int main()
{
    int T;
    cout << "Enter number of test cases: ";
    cin >> T;
    vector<vector<int>> sortedArrays(T);
    vector<int> comparisons(T, 0);
    vector<int> inversions(T, 0);
    for (int t = 0; t < T; t++)
    {
        int n;
        cout << "\nEnter size of array: ";
        cin >> n;
        vector<int> arr(n);
        cout << "Enter elements in the array: ";
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        mergeSort(arr, 0, n - 1, comparisons[t], inversions[t]);
        sortedArrays[t] = arr;
    }
    cout << "\nOutput:\n";
    for (int t = 0; t < T; t++)
    {
        cout << "Test Case " << t + 1 << ":\n";
        cout << "Sorted Array: ";
        for (int num : sortedArrays[t])
        {
            cout << num << " ";
        }
        cout << "\nComparisons: " << comparisons[t];
        cout << "\nInversions: " << inversions[t] << "\n";
    }

    return 0;
}
