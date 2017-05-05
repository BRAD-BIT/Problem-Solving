#include<iostream>
using namespace std;
int main()
{
    char x; int b = 0, w = 0; char a[4][4]; for (int i = 0; i < 4; i++){ for (int j = 0; j < 4; j++){ cin >> a[i][j]; } }
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (a[i][j] == '.')w++; else b++;
                if (a[i + 1][j] == '.')w++; else b++;
                if (a[i][j + 1] == '.')w++; else b++;
                if (a[i + 1][j + 1] == '.')w++; else b++;
                if (b == 4 || b == 3 || w == 4 || w == 3){ cout << "YES" << endl; return 0; }
                b = 0, w = 0;
            }
        }
    cout << "NO" << endl;
}