#include<iostream>
#include<string>
using namespace std;
int main()
{
    string a;
    cin >> a;
    int x = a.length();
    int h=-1, e=-1, l1=-1, l2=-1, o=-1;
    bool testh = false, teste = false, testl1 = false, testl2 = false, testo = false;
    for (int i = 0; i < x; i++)
    {
        if (a[i] == 'h')
        {
            h = i;
            testh = true;
            break;
        }
    }
    if (h != -1)
    {
        for (int i = h+1; i < x; i++)
        {
            if (a[i] == 'e')
            {
                e = i;
                teste = true;
                break;
            }
        }
        if (e != -1)
        {
            for (int i = e+1; i < x; i++)
            {
                if (a[i] == 'l')
                {
                    l1 = i;
                    testl1 = true;
                    break;
                }
            }
            if (l1 != -1)
            {
                for (int i = l1+1; i < x; i++)
                {
                    if (a[i] == 'l')
                    {
                        l2 = i;
                        testl2 = true;
                        break;
                    }
                }
                if (l2 != -1)
                {
                    for (int i = l2+1; i < x; i++)
                    {
                        if (a[i] == 'o')
                        {
                            testo = true;
                            break;
                        }
                    }
                }
            }
        }
    }
    if (testh&&teste&&testl1&&testl2&&testo)cout << "YES";
    else
    cout << "NO";
}