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
struct word{string s;int type;};
int main()
{
    int n; cin >> n; word *a = new word[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].s;
        for (int j = 2; j < a[i].s.length(); j++)
        {if (a[i].s[j]=='C'){if(a[i].s[0]=='R'&&int(a[i].s[1])<65)a[i].type=2;}}
        if (a[i].type != 2)a[i].type = 1;
    }
    for (int i = 0; i < n; i++)
    {
        if (a[i].type == 1)
        {
            string v = "R";
            for (int z = 0; z < a[i].s.length(); z++)
            {
                if (int(a[i].s[z]) < 65)v += a[i].s[z];
            }
            v +='C';
            int x = 0, j = 0, sum = a[i].s.length() - (v.length() - 1);
            while (a[i].s[j] - 48>9)
            {
                if (a[i].s[j + 1] - 48 > 9){x=x+pow(26.00, sum - j)*(a[i].s[j]-64);}
                else x=x+(a[i].s[j]-64);j++;
            }
            cout << v << x << endl;
        }
        else
        {
            string s, s1;
            for (int z = 1; z < a[i].s.length(); z++)
            {
                if (a[i].s[z] != 'C')s += a[i].s[z];
                else
                {
                    for (int j = z + 1; j < a[i].s.length(); j++){ s1 += a[i].s[j]; }break;
                }
            }
            ll n = stoll(s1); s1.clear(); char v; int y = 0;
            while (n!=0)
            {
                char c;
                if (n % 26 == 0){ c = 'Z'; n = (n / 26) - 1; }
                else { c = n % 26 + 64; n /= 26; }
                s1 += c;
            }
            reverse(s1.begin(), s1.end());
            cout << s1 << s << endl;
        }
    }
}