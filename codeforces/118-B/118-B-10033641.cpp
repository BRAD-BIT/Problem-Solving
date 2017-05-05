#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int c = (2 * n) + 1;//3
    int k = (n)* 2;//2
    int z;
    int l = 0;
    bool flag;
    int q = 0;
    for (int i = 0; i < c; i++)
    {
        z = 0;
        q = i;
        if (i>n)q = n - (i - n);
        flag = true;

        for (int j = 0; j < c; j++)
        {
            if (j < k)cout << " ";
            else
            {
                cout << z ;
                if (j != c - 1)cout << " ";
                if (z < q&&flag)z++;
                else
                {
                    z--;
                    flag = false;
                }
            }
        }
        if (i <= n - 1)k -= 2;
        else k += 2;
        cout << endl;
    }
}