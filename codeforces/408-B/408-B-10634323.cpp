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
#include<ctime>
using namespace std;
#define PI 3.14159265358979323846
#define ll long long
#define DFS_GRAY  -1
#define DFS_WHITE  0
#define DFS_BLACK  1
int main()
{
    string s1, s2; cin >> s1 >> s2; double a[26] = { 0 }, b[26] = { 0 };
    for (int i = 0; i < s1.length(); i++)a[s1[i] - 'a']++;
    for (int i = 0; i < s2.length(); i++)b[s2[i] - 'a']++;
    double max = 0;
    for (int i = 0; i < 26; i++)
    {
        if ((a[i]>b[i]&&b[i]!=0)||(a[i]==b[i]))
        {
            max += b[i];
        }
        else
        if (a[i] == 0 && b[i] != 0)
        {
            cout << -1 << endl; return 0;
        }
        else
        if (a[i] < b[i])
        {
            max += a[i];
        }
    }
    cout << max << endl;
}