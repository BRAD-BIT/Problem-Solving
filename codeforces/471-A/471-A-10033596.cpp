#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<stack>
#include<queue>
using namespace std;
int main()
{
    int a[6];
    for (int i = 0; i < 6; i++)
    {
        cin >> a[i];
    }
    sort(a, a + 6);
    bool test1 = false;
    bool test2 = false;
    bool test3 = false;
    int leg;
    for (int i = 0; i < 3; i++)
    {
        if (a[i] == a[i + 1] && a[i + 1] == a[i + 2] && a[i + 2] == a[i + 3])
        {
            test1 = true;
            leg = i;
        }
    }
    if ((leg == 0&&a[4]==a[5])||(leg==2&&a[0]==a[1]))test2 = true;
    else test3 = true;
    if (test1&&test2)cout << "Elephant";
    else
    if (test1&&test3)cout << "Bear";
    else cout << "Alien";


}