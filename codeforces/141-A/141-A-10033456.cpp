#include<iostream>
#include<algorithm>
#include<string>;
using namespace std;
int main()
{
    string a, b, c;
    cin >> a >> b >> c;
    string f = a + b;
    sort(f.begin(),f.end());
    sort(c.begin(), c.end());
    if (f == c)cout << "YES";
    else cout << "NO";
    
}