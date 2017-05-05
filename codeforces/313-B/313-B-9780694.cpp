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
    string s; int m, l, r; cin >> s >> m; int a[1000000]; int sum = 0;
    for (int i = 0; i < s.length()-1; i++)
    {
        if (s[i] == s[i + 1])sum++;
        a[i+1] = sum;
    }
    a[0] = 0;
    for (int i = 0; i < m; i++)
    {
        cin >> l >> r;
        cout << a[r-1] - a[l-1] << endl;
    }
    return 0;
}