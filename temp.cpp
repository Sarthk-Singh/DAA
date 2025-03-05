#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int t;
    cout << "Enter Number of Test Cases: ";
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n;
        cout << "Enter the Number of Elements : ";
        cin >> n;
        vector<int> v(n);
        for (int j = 0; j < n; j++)
        {
            cin >> v[j];
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                auto it = find(v.begin(), v.end(), v[i] + v[j]);
                if (it != v.end())
                {
                    int index = distance(v.begin(), it);
                    cout << i << " " << j << " " << index << endl;
                }
            }
        }
    }
    return 0;
}