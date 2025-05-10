//
#include <iostream>
#include <vector>
using namespace std;
vector<int> activitySelect(int n,vector<int>s,vector<int>f)
{
    vector<pair<int,pair<int,int>>>v;
    for(int i=0;i<n;i++)
    {
        v.push_back({f[i],{s[i],i}});
    }
    sort(v.begin(),v.end());
    int time=v[0].first;
    vector<int>ans;
    ans.push_back(v[0].second.second + 1);
    for(int i=1;i<n;i++)
    {
        int stime=v[i].second.first;
        int etime=v[i].first;
        if(time<=stime)
        {
            time=etime;
            ans.push_back(v[i].second.second+1);
        }
    }
    return ans;
}
int main()
{
    int n;
    cout<<"Enter the number of activities: ";
    cin>>n;
    vector<int>start(n);
    vector<int>finish(n);
    //cout<<"Enter the start time"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>start[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>finish[i];
    }
    vector<int>ans=activitySelect(n,start,finish);
    for(auto it:ans)
    {
        cout<<it<<" ";
    }
    return 0;
}
/*
n=10
1 3 0 5 3 5 8 8 2 12
4 5 6 7 9 9 11 12 14 16
*/