#include <iostream>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

void countSort(vector<char> &arr)
{

    vector<int> freq(26);
    for (int i = 0; i < arr.size(); i++)
    {
        freq[arr[i] - 'a']++;
    }

    int maxi = 0;
    int store;
    for (int i = 0; i < 26; i++)
    {
        if (freq[i] > maxi)
        {
            store = i;
            maxi = freq[i];
        }
    }

    char alp = store + 'a';
    if(maxi==1)
        cout<<"No duplicates found"<<endl;
    else
        cout << alp<<"-"<<maxi;
}

int main()
{
    int n;
    cout << "Enter the number of elements : ";
    cin >> n;
    vector<char> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    countSort(arr);
}