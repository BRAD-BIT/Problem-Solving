#include<iostream>
#include<map>
#define lop(i,a,n)   for(int i=a;i<n;++i)
#define ll         long long
using namespace std;
const int MAX=4*1e5 +7;
ll arr[MAX];
int main()
{
    ll n,k,out=0; cin>>n>>k;map<ll,ll>mp1,mp2;
    lop(i,0,n)cin>>arr[i];
    for (int i=n-1;i>=0;i--)
    {
        if (i<n-2)out+=mp2[arr[i]*k];
        if (i<n-1&&i>0)mp2[arr[i]]+=mp1[arr[i]*k];
        mp1[arr[i]]++;
    }
    cout<<out<<endl;
}