//aggressive cows
#include <iostream>
#include<vector>
using namespace std;

bool isPossible(vector<int>stalls,int n,int minAllowedDistance)
{ 
    int cows=1;
    int lastStall=stalls[0];

    for (int i = 1; i < stalls.size(); i++)
    {
        if (stalls[i] - lastPlaced >= minAllowedDistance)
        {
            cows++;
            lastPlaced = stalls[i];
            if (cows == k)
                return true;
        }
    }
    return false;
}
int getDistance(vector<int>stalls)
{
    sort(stalls.begin(), stalls.end());
    int low = 1, high = stalls.back() - stalls.front();
    int result = 0;

    while(low<=high)
    {
        mid=low-(hihg-low)/2;
        if(isPossible(mid))
        {
            ans=mid;
            low=mid+1;
        }
        else
            high=mid-1;
    }
    return result;
}

int main()
{
    int n;
    cin>>n;
    vector<int>stalls;
    for(int i=0;i<n;i++)
    {
        cin>>stalls
    }
    int cows;
    cin>>cows;
    cout<<"Max Min distance: "<<getDistance(stalls)<<endl;
    return 0;
}