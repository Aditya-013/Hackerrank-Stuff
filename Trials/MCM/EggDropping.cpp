#include <iostream>
#include <climits>
#include <cstring>
int t[100][100];
int solve(int n, int k)
{
    if (t[n][k] != -1)
    {
        return t[n][k];
    }

    if (k == 0 || k == 1)
    {
        return k;
    }
    if (n == 1)
    {
        return k;
    }
    int mn = INT_MAX;
    int res = 0;
    int i, one, two;
    for (i = 1; i <= k; i++)
    {
        if (t[n - 1][i - 1] != -1)
        {
            one = t[n - 1][i - 1];
        }
        else
        {
            one = solve(n - 1, i - 1);
        }
        if (t[n][k - i] != -1)
        {
            two = t[n][k - i];
        }
        else
        {
            two = solve(n, k - i);
        }
        res = std::max(one, two);
        if (res < mn)
        {
            mn = res;
        }
    }
    return t[n][k] = mn + 1;
}

int main()
{
    int n = 20, k = 100; //n= number of egg; k=number of floors
    memset(t, -1, sizeof(t));
    std::cout << "The minimum number of checks are:: " << solve(n, k) << std::endl;
}
