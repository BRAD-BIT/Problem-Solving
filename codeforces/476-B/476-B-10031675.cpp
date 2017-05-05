#include<iostream>
#include<string>
#include<cstring>
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
    string s1, s2; int sum1 = 0, sum2 = 0, sum = 0; cin >> s1 >> s2; int sumP1 = 0, sumN1 = 0, sumP2 = 0, sumN2 = 0;
    for (int i = 0; i < s1.length(); i++)
    {
        if (s1[i] == '+'){ sum1++; sumP1++; }
        if (s1[i] == '-'){ sum1--; sumN1++; }
        if (s2[i] == '+'){ sum2++; sumP2++; }
        if (s2[i] == '-'){ sum2--; sumN2++; }
        if (s2[i] == '?')sum++;
    }
    if ((sum1 == sum2&&sum == 0) || (sum1 == sum2&&sum % 2 != 0))cout << 1.00000000000000 << endl;
    else
    if ((sum1 != sum2) && sum == 0)cout << .0000000000000 << endl;
    else
    {
        double oraginal = sum2, sum3 = 0; int x = sum, y = 0;
        while (y != sum + 1)
        {
            sum2 += (x - y);
            if (sum1 == sum2){ sum3++; break; }
            sum2 = oraginal;
            x--, y++;
        }
        if (sum3 == 0)cout << .00000000000 << endl;
        else
        {
            string s; double ans = 0;
            for (int i = 0; i < x; i++)s += '+'; for (int i = 0; i < y; i++)s += '-'; sort(s.begin(), s.end());
            do
            {
                ans++;
            } while (next_permutation(s.begin(), s.end()));
            cout << fixed << setprecision(10) <<ans/ pow(2, double(sum)) << endl;
        }
    }
}