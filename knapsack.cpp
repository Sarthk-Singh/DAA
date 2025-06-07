// daa lab week 9 questionn 2
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

double knapsack(int n, vector<double> &val, vector<double> &wt, int capacity)
{
    double ans = 0.0;
    vector<pair<double, pair<double, double>>> v;

    // Calculate value-to-weight ratio
    for (int i = 0; i < n; i++)
    {
        v.push_back({val[i] / wt[i], {wt[i], val[i]}});
    }

    // Sort in descending order of value-to-weight ratio
    sort(v.rbegin(), v.rend());

    for (auto it : v)
    {
        double ratio = it.first;
        double weight = it.second.first;
        double value = it.second.second;

        if (capacity >= weight)
        {
            capacity -= weight;
            ans += value;
        }
        else
        {
            ans += capacity * ratio;
            break;
        }
    }

    return ans;
}

int main()
{
    int n;
    cout << "Enter the number of items: ";
    cin >> n;

    int size;
    cout << "Enter the size of knapsack: ";
    cin >> size;

    vector<double> wt(n), val(n);
    cout << "Enter the item's weight and value:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> wt[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>val[i];
    }
    double ans = knapsack(n, val, wt, size);
    cout << "Max value of knapsack is: " << ans << endl;

    return 0;
}
/*
size=16
6 10 3 5 1 3
6 2 1 8 3 5
*/