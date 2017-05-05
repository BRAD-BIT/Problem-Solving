#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include <functional>
#include <sstream>
#include<stack>
#include<queue>
struct child
{
    int a;
    int pos;
};
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    queue<child>q;
    for (int i = 0; i < n; i++)
    {
        child m;
        cin >> m.a;
        m.pos = i + 1;
        q.push(m);
    }
    int d;
    while (!q.empty())
    {
        q.front().a -= k;
        d = q.front().pos;
        if (q.front().a <= 0)
        {
            q.pop();
        }
        else
        {
            q.push(q.front());
            q.pop();
        }
    }
    cout << d;
}