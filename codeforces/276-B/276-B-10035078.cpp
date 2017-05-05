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
    int a[26] = { 0 }; string s; cin >> s;
    for (int i = 0; i < s.length(); i++){a[s[i] - 'a']++;}
    int odds = 0;
    for (int i = 0; i < 26; i++)if (a[i] % 2 != 0)odds++;
    if (odds==0||odds%2==1)cout << "First"; else cout << "Second";
}