#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include <functional>
#include <sstream>
#include<stack>
#include<queue>
#include <bitset> 
using namespace std;
struct ass
{
    int value;
    int pos;
};
bool comp(ass a, ass b)
{
    return a.value < b.value;
}
int main()
{
    long long n, k,f,t;
    cin >> n >> k;
    long long max = -11111111111111111;
    for (int i = 0; i < n; i++)
    {
        int z;
        cin >> f >> t;
        if (t>k)z = f - (t - k);
        else z = f;
        if (z>max)max = z;
    }
    cout << max;
}