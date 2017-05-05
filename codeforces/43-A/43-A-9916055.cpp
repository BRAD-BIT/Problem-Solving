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
struct team{string name;int goals;};
int main()
{
    int n; cin >> n; team a, b; a.goals = 0, b.goals = 0; string s; a.name = 'a', b.name = 'b';
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        if (a.name == "a"){ a.name = s; a.goals++; }
        else
        if (b.name == "b"&&a.name != s){ b.name = s; b.goals++; }
        else
        if (s == a.name)a.goals++;
        else
            b.goals++;
    }
    if (a.goals > b.goals)cout << a.name << endl; else cout << b.name << endl;
}