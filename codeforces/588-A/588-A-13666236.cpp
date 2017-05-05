#include<bits/stdc++.h>
using namespace std;
int ocr[10000000+7];
int main()
{
    int n,ans=0,m=1e9;cin>>n;
    for(int i=0;i<n;i++)
    {
        int a,p;cin>>a>>p;
        m=min(m,p);
        ans+=a*m;
    }
    cout<<ans<<endl;
}