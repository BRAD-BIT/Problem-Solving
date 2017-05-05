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
struct user{ ll value, index; };
bool comp1(user a, user b){ return a.value < b.value; }
bool comp2(user a, user b){ return a.index < b.index; }
int main()
{
    int n; cin >> n; user *a = new user[n];
    for (int i = 0; i < n; i++){ cin >> a[i].value; a[i].index = i; }
    sort(a, a + n, comp1);
    int sum = 0, x = a[0].value; user *b = new user[n];
    for (int i = 0; i < n; i++)
    {
        if (a[i].value != x)
        {
            if (x + sum-1 < a[i].value)
            {
                x = a[i].value;
                sum = 0;
            }
            else
            {
                sum = (x + sum) - a[i].value;
                x = a[i].value;
            }
        }
        b[i].value = a[i].value + sum; b[i].index = a[i].index;
        sum++;
    }
    sort(b, b + n, comp2);
    for (int i = 0; i < n; i++)cout << b[i].value << " "; cout << endl;
}