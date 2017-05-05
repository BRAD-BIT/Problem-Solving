#include<bits/stdc++.h>
#define lop(i,a,b) for(int i=a;i<b;++i)
#define loop(i,a,b) for(int i=a-1;i>=b;--i)
using namespace std;
int const MAX=2000 +7;
long long int isPal[MAX][MAX],sum[MAX];
int main()
{
    string s;cin>>s;
    long long int N=s.length(),ans=0;
    lop(i,0,N)isPal[i][i]=1;

    lop(L,2,N+1)
    lop(i,0,N-L+1)
    {
        int j=i+L-1;
        if(L==2)isPal[i][j]=(s[i]==s[j]);
        else isPal[i][j]=(s[i]==s[j])&&(isPal[i+1][j-1]);
    }
    lop(i,0,N)lop(j,0,N)sum[i]+=isPal[i][j];
    loop(i,N-1,0)sum[i]+=sum[i+1];
    lop(i,0,N)lop(j,i,N)if(isPal[i][j])ans+=sum[j+1];
    cout<<ans<<endl;
}