#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void check(vector<int> &arr, int key)
{
    int n = arr.size();
    int i = 0;
    int j = n - 1;
    int flag = 0;

    while (i < j)
    {
        if (arr[i] + arr[j] == key)
        {
            cout << arr[i] << " " << arr[j];
            flag = 1;
            break;
        }
        else if (arr[j] > key)
        {
            j--;
        }
        else
        {
            i++;
        }
    }
    if (flag == 0)
    {
        cout << "No Such elements Exits";
    }
}

int main()
{
    int n;
    cout << "Enter the Number of Element : ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter the Elements : ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());
    int key;
    cout << "Enter the Key : ";
    cin >> key;
    check(arr, key);
}