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
struct task
{
    int difficulty;
    int pos;
};
bool comp(task a, task b)
{
  return a.difficulty < b.difficulty;
}
int main()
{
    int n; cin >> n; task *a = new task[n]; for (int i = 0; i < n; i++){cin >> a[i].difficulty; a[i].pos = i + 1;}
    sort(a, a + n, comp);
    int sum = 0;
    for (int i = 0; i < n-1; i++)
    {
        if (a[i].difficulty == a[i + 1].difficulty)sum++;
    }
    if (sum < 2)cout << "NO" << endl;
    else
    {
        sum = 0;
        cout << "YES" << endl;
        for (int i = 0; i < n; i++)cout << a[i].pos << " "; cout << endl;
        for (int v = 0; v < n-1; v++)
        {
            if (sum == 2)return 0;
            if (a[v].difficulty == a[v + 1].difficulty){ swap(a[v], a[v + 1]); for (int i = 0; i < n; i++)cout << a[i].pos << " "; cout << endl; sum++; }
        }
    }
}