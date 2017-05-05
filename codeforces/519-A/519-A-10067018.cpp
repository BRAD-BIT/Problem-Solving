#include<iostream>
#include<string>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<functional>
#include<sstream>
#include<stack>
#include<queue>
#include<bitset> 
#include<iomanip>
#include<vector>
#include<map>
#include<set>
#include<list>
#include<stdio.h>
#include<fstream>
using namespace std;
#define PI 3.14159265358979323846
#define ll long long
int main()
{
    int sumW = 0, sumB = 0; char x;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            cin >> x;
            if (x == 'Q')sumW+=9;
            if (x == 'R')sumW+=5;
            if (x == 'B')sumW+=3;
            if (x == 'N')sumW+=3;
            if (x == 'P')sumW+=1;

            if (x == 'q')sumB+=9;
            if (x == 'r')sumB+=5;
            if (x == 'b')sumB+=3;
            if (x == 'n')sumB+=3;
            if (x == 'p')sumB+=1;
        }
    }
    if (sumW > sumB)cout << "White";
    else
    if (sumB > sumW)cout << "Black";
    else
        cout << "Draw";
}