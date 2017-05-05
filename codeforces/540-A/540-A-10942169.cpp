#define _crt_secure_no_warnings
#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<unordered_map>
#include<queue>
#include<stack>
#include<iterator>
#include<cmath>
#include<string>
#include<sstream>
#include<cstring>
#include<ctype.h>
#include<iomanip>
#include<bitset>
#include<stdio.h>
#include<fstream>
#include<regex>
#include<stdlib.h>
#include<math.h>
using namespace std;

long long n, m;string s, t;
int ass(int xx, int yy)
{
    int ans = 0;int st = 0;
    for (int i = xx; i != yy;){st++;i++;i %= 10;}
    ans = st;st = 0;
    for (int i = yy; i != xx;)
    {st++;i++;i %= 10;}
    ans = min(ans, st);
    return ans;
}

int main()
{
    cin >> n;cin >> s >> t;int ans = 0;
    for (int i = 0; i < n; i++){ans += ass(s[i] - '0', t[i] - '0');}cout << ans;
}