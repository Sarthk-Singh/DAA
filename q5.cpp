#include <iostream>
#include <vector>
#include <map>
using namespace std;
void threeIndices(int n , vector<int> &v,vector<vector<int>> &resu){
map<int, int> mp;
for(int i=0;i<n;i++){
    mp[v[i]] = i;
}
for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
        int sum = v[i]+v[j];
        if(mp.find(sum)!=mp.end() && mp[sum] > j){
            resu.push_back({i+1,j+1,mp[sum]+1});
            return ;   }
    }
}
resu.push_back({-1});
}
int main(){
    int k;
    cout<<"Enter the Number of Test Cases : ";
    cin>>k;
    vector<vector<int>> results;
    for(int i=0;i<k;i++){
        int n;
        cout<<"Enter the Number of Elements : ";
        cin>>n;
        vector<int> v(n);
        for(int i=0;i<n;i++){
            cin>>v[i];
        }
        threeIndices(n,v,results);
    }
    cout<<endl;
    for (int i = 0; i < k; i++) {
        for (int num : results[i]) {
            if(num!=-1){
            cout<<num<<" ";
            }
            else{
                cout<<"No Sequence Found";
            }
        }
        cout<<endl;  
    }
}