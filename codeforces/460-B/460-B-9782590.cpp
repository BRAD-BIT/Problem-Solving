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
long long m[10000];
int main()
{
    int a, b, c; cin >> a >> b >> c;
    int l = 0;
    int sum = 0;
    long long n = 1000000000;
    if (a == 1)n = 10000;
    for (double i = 1; i <= n; i++)
    {
        long long h = 0;
        long long z = b*pow(i, a) + c;
        if (z > 1000000000)break;
        if (z > 0)
        {
            stringstream ss;
            ss << z;
            string s = ss.str();
            for (int v = 0; v < s.length(); v++)
            {
                h += (s[v] - 48);
            }
            if (h == i)
            {
                sum++;
                m[l] = z;
                l++;
            }
        }
    }
    cout << sum << endl;
    for (int i = 0; i < sum; i++){ cout << m[i] << " "; }
}