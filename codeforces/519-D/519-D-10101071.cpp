#include<iostream>
#include<string>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<functional>
#include<sstream>
#include<stack>
#include<queue>
#include<bitset> 
#include<iomanip>
#include<vector>
#include<map>
#include<set>
#include<list>
#include<stdio.h>
#include<fstream>
using namespace std;
#define PI 3.14159265358979323846
#define ll long long
int main()
{
    int a[26];map<ll, ll> M[26]; ll ans = 0, sum = 0;
    for (int i = 0; i < 26; i++)cin >> a[i]; string s; cin >> s;
    for (int i = 0; i < s.length(); i++)
    {
        ans += M[s[i] - 'a'][sum];sum += a[s[i] - 'a'];M[s[i] - 'a'][sum]++;
    }
    cout << ans << endl;
}