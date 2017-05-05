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
struct subject{ ll a, b; };
bool comp(subject a, subject b)
{
    return a.b < b.b;
}
int main()
{
    ll n, r, avg; cin >> n>> r>> avg; ll z = avg*n; subject *a = new subject[n]; ll zum = 0;
    for (int i = 0; i < n; i++){ cin >> a[i].a >> a[i].b; zum += a[i].a; }sort(a, a + n, comp);
    ll sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (zum >= z){ cout << sum << endl; return 0; }
        if (a[i].a < r)
        {
            if (z - zum>r - a[i].a){zum += (r - a[i].a);sum += (r - a[i].a)*a[i].b;}
            else{sum += (z - zum)*a[i].b;zum = z;}
        }
    }
    if (zum >= z){ cout << sum << endl; return 0; }
}