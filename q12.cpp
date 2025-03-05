#include <iostream>
#include <vector>

using namespace std;

int maximum(vector<int> &arr)
{
    int maxEle = arr[0];
    for (int i = 1; i < arr.size(); i++)
    {
        maxEle = max(arr[i], maxEle);
    }
    return maxEle;
}

int minimum(vector<int> &arr)
{
    int minEle = arr[0];
    for (int i = 1; i < arr.size(); i++)
    {
        minEle = min(arr[i], minEle);
    }
    return minEle;
}

int CountSort(vector<int> &arr, int k)
{
    int n = arr.size();
    int maxi = maximum(arr);
    int mini = minimum(arr);
    int size = (maxi - mini) + 1;

    vector<int> freqArr(size, 0);

    for (int i = 0; i < n; i++)
    {
        int ind = arr[i] - mini;
        freqArr[ind]++;
    }

    for (int i = 1; i < size; i++)
    {
        freqArr[i] += freqArr[i - 1];
    }

    if (k > n || k <= 0)
    {
        return -1;
    }

    for (int i = 0; i < size; i++)
    {
        if (freqArr[i] >= k)
        {
            return (i + mini);
        }
    }
    return -1;
}

int main()
{
    int T;
    cout << "Enter number of test cases: ";
    cin >> T;

    vector<int> results(T);

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
        int k;
        cout << "Enter the value of K: ";
        cin >> k;

        results[t] = CountSort(arr, k);
    }

    cout << "\nOutput:\n";
    for (int t = 0; t < T; t++)
    {
        if (results[t] == -1)
        {
            cout << "Test Case " << t + 1 << ": Invalid K value!\n";
        }
        else
        {
            cout << "Test Case " << t + 1 << ": Kth Smallest Element = " << results[t] << "\n";
        }
    }

    return 0;
}
