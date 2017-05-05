#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include <functional>
#include <sstream>
#include<stack>
#include<queue>
using namespace std;
struct word
{
    string m;
    int type;
};
int main()
{
    int n;
    cin >> n;
    if (n % 2 == 0)
    {
        cout << (n*n) / 2 << endl;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i % 2 == 0)
                {
                    if (j % 2 == 0)cout << "C";
                    else cout << ".";
                }
                else
                {
                    if (j % 2 == 0)cout << ".";
                    else cout << "C";
                }
            }
            cout << endl;
        }
    }
    else
    {
        cout << (n*n) / 2 + 1 << endl;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i % 2 == 0)
                {
                    if (j % 2 == 0)cout << "C";
                    else cout << ".";
                }
                else
                {
                    if (j % 2 == 0)cout << ".";
                    else cout << "C";
                }
            }
            cout << endl;
        }
    }
}