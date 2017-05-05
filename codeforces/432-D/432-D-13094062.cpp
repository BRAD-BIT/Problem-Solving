#include <bits/stdc++.h>
#include <ext/numeric>
using namespace std;
using namespace __gnu_cxx;

void Z_Algrothim(string str) {
    int n = str.length();
    vector<int> Z(n, 0), freq(n + 1, 0);
    int L = 0, R = 0;
    Z[0] = n;
    for (int i = 1; i < n; i++) {
    if (i <= R)Z[i] = min(Z[i - L], R - i + 1);
    while (i + Z[i] < n && str[Z[i]] == str[i + Z[i]])Z[i]++;
    if (Z[i]+i-1 > R)L = i, R = i + Z[i] - 1;
    }
    int ans = 0, cur = 0;
    for (int i = 0; i < n; i++) {if (Z[i])freq[0]++, freq[Z[i]]--;}
    for (int i = 0; i < n; i++) {cur += freq[i];freq[i] = cur;
    ans += (Z[n - i - 1] + n - i - 1 == n);}
    cout << ans << endl;
    for (int i = 0; i < n; i++)if (Z[n - i - 1] + n - i - 1 == n)
            cout << i + 1 << " " << freq[i] << endl;
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin);
    //freopen("out.txt", "wt", stdout);
#endif
    string s;
    cin >> s;
    Z_Algrothim(s);
}