#include<iostream>
#include<string>
#include<set>
using namespace std;
int main()
{
    int n, m; cin >> n >> m; string *a = new string[n]; for (int i = 0; i < n; i++)cin >> a[i]; 
    int *b = new int[m]; for (int i = 0; i < m; i++)b[i] = 0;
    for (int i = 0; i < m; i++){for (int j = 0; j < n; j++){if (a[j][i]>b[i]){ b[i] = a[j][i]; }}}
    set<int> s;
    for (int i = 0; i < n; i++){for (int j = 0; j < m; j++){if (a[i][j] >= b[j])s.insert(i);}}
    cout << s.size() << endl;
}