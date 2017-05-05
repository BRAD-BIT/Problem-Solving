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
struct laptop
{
    int price;
    int quality;
};
bool comp(laptop a, laptop b)
{
  return a.price < b.price;
}
int main()
{
    long long n;
    cin >> n;
    laptop *a = new laptop[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].price >> a[i].quality;
    }
    sort(a, a + n, comp);
    bool test = false;
    for (int i = 0; i<n-1; i++)
    {
        if ((a[i].price<a[i+1].price) && (a[i].quality>a[i + 1].quality))
        {
            test = true;
            break;
        }
    }
    if (test)cout << "Happy Alex";
    else cout << "Poor Alex";
}