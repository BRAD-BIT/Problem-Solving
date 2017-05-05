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
#include <stdio.h>
#include<fstream>
using namespace std;
int main()
{
    string s; int k, sum = 0; cin >> s >> k; int a[26]; for (int i = 0; i < 26; i++)cin >> a[i];
    for (int i = 0; i < s.length(); i++)
    {
        int z = s[i] - 97;
        sum += (a[z]*(i+1));
    }
    sort(a, a + 26);
    for (int i = s.length() + 1; i <= s.length() + k; i++)
    {
        sum += (a[25] * (i));
    }
    cout << sum << endl;
}