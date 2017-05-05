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
bool Is_Lucky(long long n)
{
    stringstream ss;
    ss << n;
    string s = ss.str();
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '8')return true;
    }
    return false;
}
int main()
{
    long long n,sum=0; cin >> n;
    while (true)
    {
        n++;
        sum++;
        if (Is_Lucky(n)){ cout << sum << endl; return 0; }
    }
}