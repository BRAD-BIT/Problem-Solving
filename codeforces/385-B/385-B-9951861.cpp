#include<iostream>
#include<string>
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
    string s; cin >> s; vector<int> v;
    if (s.length() >= 4)
    {
        for (int i = 0; i < s.length() - 3; i++)
        {
            if (s[i] == 'b'&&s[i + 1] == 'e'&&s[i + 2] == 'a'&&s[i + 3] == 'r')v.push_back(i);
        }
    }
    int sum = 0;
    if (v.size() != 0)
    {
        sum += (v[0] + 1)*(s.length() - (v[0] + 3));
        for (int i = 1; i < v.size(); i++)
        {
            sum += (v[i] - (v[i - 1]))*(s.length() - (v[i] + 3));
        }
    }
    cout << sum << endl;
}