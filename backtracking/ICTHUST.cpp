#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

int n, M;
int a[1000];
int x[1000];
int f;
int t[1000];
int countt = 0;
int useCheck[1000] = {0};

void Try(int k)
{
    // int v;
    //  int maxx = (M - f - (t[n] - t[k])) / a[k];
    for (int v = 1; v <= 9; v++)
    {
        if (useCheck[v] == 0)
        {
            x[k] = v;
            useCheck[v] = 1;
            f += a[k] * x[k];
            if (k == n)
            {
                if (f == M)
                {
                    countt++;
                }
            }
            else
            {
                Try(k + 1);
            }
            useCheck[v] = 0;
            f -= a[k] * x[k];
        }
    }
}

int main()
{
    // scanf("%d %d", &n, &M);
    // for (int i = 1; i <= n; i++)
    // {
    //     scanf("%d", &a[i]);
    // }
    n = 7;
    cin >> M;
    M = M + 62;
    a[1] = -100;
    a[2] = 100;
    a[3] = 10;
    a[4] = 2;
    a[5] = 1000;
    a[6] = 100;
    a[7] = 10;

    a[0] = 0;
    x[0] = 0;
    f = 0;
    countt = 0;
    t[1] = a[1];
    for (int i = 2; i <= n; i++)
    {
        t[i] = t[i - 1] + a[i];
    }
    Try(1);
    printf("%d\n", countt);
}