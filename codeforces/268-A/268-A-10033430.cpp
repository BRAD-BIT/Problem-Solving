#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
struct team
{
    int home;
    int guest;
};
int main()
{
    int n;
    cin >> n;
    team *a = new team[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].home >> a[i].guest;
    }
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i].home == a[j].guest)sum++;
        }
    }
    cout << sum;
    return 0;
}