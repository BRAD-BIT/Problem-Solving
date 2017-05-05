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
    int posE;
    int posO;
    int sumE = 0;
    int sumO = 0;
    for (int i = 0; i < n; i++)
    {
        int z;
        cin >> z;
        if (z % 2 == 0)
        {
            posE = i + 1;
            sumE++;
        }
        else
        {
            posO = i + 1;
            sumO++;
        }
    }
    if (sumO == 1)cout << posO;
    else cout << posE;
}