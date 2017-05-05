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
    int n;
    cin >> n;
    int cur = 0;
    int health = 0;
    int com;
    int sum=0;
    for (int i = 0; i < n; i++)
    {
        cin >> com;
        if (com>cur)
        {
            health -= (com-cur);
            if (health < 0)
            {
                health += (com - cur);
                sum = sum + com - cur-health;
                health = 0;
            }
            cur = com;
        }
        else if (cur >= com)
        {
            health += (cur - com);
            cur = com;
        }
        
    }
    cout << sum;
}