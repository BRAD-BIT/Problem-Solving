#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include <functional>
#include <sstream>
#include<stack>
#include<queue>
#include <bitset> 
#include<iomanip>
#include<vector>
#include<map>
#include<set>
using namespace std;
int main()
{
    int p, n; cin >> p >> n; map<int, bool> s;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        long long x;
        cin >> x;
        long long z = x % p;
        if (s[z])sum++;
        else s[z] = true;
        if (sum == 1){cout << i+1; break;}
    }
    if (sum != 1)cout << -1;
}