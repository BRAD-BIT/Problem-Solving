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
    int n; cin >> n; string s1, s2; cin >> s1;
    for (int i = 0; i < n; i++)
    {
        if (s1[i] != '1'&&s1[i] != '0')
        {
            if (s1[i] == '4')s2 += "322"; else if (s1[i] == '6')s2 += "53"; else if (s1[i] == '8')s2 += "7222"; else if (s1[i] == '9')s2 += "7332"; else s2 += s1[i];
        }
    }
    sort(s2.begin(), s2.end(), greater<char>());
    cout << s2 << endl;
}