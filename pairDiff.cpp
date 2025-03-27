#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool countPairsWithDifference(vector<int> &arr, int k)
{
    sort(arr.begin(), arr.end());
    int i = 0, j = 1, n = arr.size();

    while (j < n)
    {
        int diff = arr[j] - arr[i];

        if (diff < k)
        {
            j++;
        }
        else if (diff > k)
        {
            i++;
        }
        else
        {
            return true;
        }
        if (i == j)
            j++;
    }
    return false;
}

int main()
{
    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter the elements of the array: ";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<"Enter the value of k: ";
    int k;
    cin>>k;
    if(countPairsWithDifference(arr, k))
        cout<<"TRUE\n";
    else
        cout<<"FALSE\n";
    return 0;
}
