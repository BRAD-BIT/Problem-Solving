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
    int n; cin >> n; string s; cin >> s;
    string x = s;
    x.erase(n, n);
    string y = s;
    y.erase(0, n);
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    s = y;
    string s1 = s;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if ((x[i]>s[j]) && (s[j] != '#'))
            {
                s[j] = '#';
                break;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if ((x[i] < s1[j]) && (s1[j] != '#'))
            {
                s1[j] = '#';
                break;
            }
        }
    }
    bool test1 = true;
    bool test2 = true;
    for (int j = 0; j < n; j++)
    {
        if (s[j] != '#')test1 = false;
    }
    for (int j = 0; j < n; j++)
    {
        if (s1[j] != '#')test2 = false;
    }
    if (test1 || test2)cout << "YES";
    else cout << "NO";

}