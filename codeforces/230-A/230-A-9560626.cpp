#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include <functional>
#include <sstream>
#include<stack>
#include<queue>
using namespace std;
struct dragon
{
    int health;
    int forme;
};
bool comp(dragon a, dragon b)
{
    return a.health < b.health;
}
int main()
{
    int s, n;
    cin >> s >> n;
    dragon *a = new dragon[n];
    bool test = true;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].health >> a[i].forme;
    }
    cout << endl;
    sort(a, a + n,comp);
    for (int i = 0; i < n; i++)
    {
    if (s>a[i].health)
    {
    s = s + a[i].forme;
    }
    else
    {
    test = false;
    }
    }
    if (test)cout << "YES";
    else cout << "NO";
}
/*stringstream ss;
ss << int name;
string string name = ss.str();*/


//sort(arrayname, arrayname + n, [](A a, A b){ return a.strct1 < b.strct1; });
//sort(arrayname, arrayname + n, [](A a, A b){ return a.strct2 < b.strct2; });