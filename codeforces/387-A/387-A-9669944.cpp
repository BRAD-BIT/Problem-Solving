#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include <functional>
#include <sstream>
#include<stack>
#include<queue>
#include <bitset> 
using namespace std;
int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    int a = s1[0] * 10 + s1[1] - 2 * 48;
    int b = s1[3] * 10 + s1[4] - 2 * 48;
    int c = s2[0] * 10 + s2[1] - 2 * 48;
    int d = s2[3] * 10 + s2[4] - 2 * 48;
    int h = a - c;
    int m = b - d;
    if (m < 0)
    {
        m += 60;
        h--;
    }
    if (h < 0)h += 24;
    if (h < 10)cout << 0 << h<<":";
    else cout << h << ":";
    if (m < 10)cout << 0 << m;
    else cout << m;
}