#include<algorithm>
#include<stdlib.h>
#include<iterator>
#include<iostream>
#include<numeric>
#include<sstream>
#include<cstring>
#include<ctype.h>
#include<iomanip>
#include<stdio.h>
#include<fstream>
#include<vector>
#include<bitset>
#include<string>
#include<math.h>
#include<queue>
#include<stack>
#include<cmath>
#include<set>
#include<map>
using namespace std;
#define PI 3.14159265358979323846
#define ll long long
int main()
{
    int n; string s; cin >> n >> s;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (s[j] == '*')
            {
                int ans = 0;
                for (int z = j; z < n; z++)
                {
                    if (i + z < n)
                    {
                        if (s[z + i] == '*'){ ans++; z = z + i - 1; }
                        else break;
                    }
                    if (ans == 4){ cout << "YES"; return 0; }
                }
            }
        }
    }
    cout << "NO" << endl;
}