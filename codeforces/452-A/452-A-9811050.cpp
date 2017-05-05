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
int main()
{
    string s; int n; cin >> n >> s; string a[6] = { "jolteon", "flareon", "umbreon", "leafeon", "glaceon", "sylveon" };
    if (n == 8)cout << "vaporeon" << endl;
    else
    if (n == 6)cout << "espeon" << endl;
    else
    {int max[6] = { 0 };
    for (int i = 0; i < 6; i++)
    {if (s[i] != '.')
    {
    if (s[i] == a[0][i])max[0]++;if (s[i] == a[1][i])max[1]++; if (s[i] == a[2][i])max[2]++;
    if (s[i] == a[3][i])max[3]++;if (s[i] == a[4][i])max[4]++; if (s[i] == a[5][i])max[5]++;}}
    int v = max[0]; int z = 0;
    for (int i = 0; i < 6; i++){if (max[i]>v){v = max[i];z = i;}}
    cout << a[z] << endl;}
}