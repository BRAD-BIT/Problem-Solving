#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int n,ans=1;
    cin>>n;
    for(long long int i=2;i*i<=n;i++)
    {
        if(n%i==0)ans*=i;
        while(n%i==0){n/=i;}
    }
    cout<<n*ans;
}