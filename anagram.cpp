#include <iostream>
#include<map>
using namespace std;

bool checkAnagram(string s1, string s2)
{
    int l1=s1.length();
    int l2=s2.length();
    
    map<char,int>mp;
    if(l1!=l2)
        return false;
    for(int i=0;i<l1;i++)
    {
        mp[s1[i]]++;
    }
    for(int i=0;i<l2;i++)
    {
        mp[s2[i]]--;
    }
    for(auto it=mp.begin();it!=mp.end();it++)
    {
        if(it->second!=0)
            return false;
    }
    return true;
}

int main()
{
    string s1,s2;
    cout<<"Enter the first string: "endl;
    cin>>s1;
    cout << "Enter the second string: " endl;
    cin>>s2;
    if(checkAnagram(s1,s2))
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
    return 0;
}