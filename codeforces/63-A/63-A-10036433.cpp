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
struct crew{ string name, type;};
int main()
{
    string a[] = { "rat", "woman", "child", "man" }; int n; cin >> n; crew b[100]; string c;
    for (int i = 0; i < n; i++){ cin >> b[i].name >> b[i].type; if (b[i].type == "captain")c = b[i].name;}
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0){ if (b[j].type == a[0])cout << b[j].name << endl; }
            if (i == 1){ if (b[j].type == a[1])cout << b[j].name << endl; }
            if (i == 1){ if (b[j].type == a[2])cout << b[j].name << endl; }
            if (i == 2){ if (b[j].type == a[3])cout << b[j].name << endl; }
        }
    }
    cout << c << endl;
}