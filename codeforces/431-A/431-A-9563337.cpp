#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include <functional>
#include <sstream>
#include<stack>
#include<queue>
using namespace std;
int main()
{
    int a[4];
    cin >> a[0] >> a[1] >> a[2] >> a[3];
    string s;
    cin >> s;
    int sum = 0;
    for (int i = 0; i < s.length(); i++)
    {
        int z = s[i] - 49;
        sum = sum + a[z];
    }
    cout<<sum;
}