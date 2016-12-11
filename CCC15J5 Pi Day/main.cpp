#include <bits/stdc++.h>

using namespace std;

vector<vector<vector<int> > > dp(251, vector<vector<int> >(251, vector<int> (251, 0)));

int recursion(int k, int n, int t)
{
    if (n == 1 || k == n)
    {
        return 1;
    }
    if (dp[k][n][t] != 0)
    {
        return dp[k][n][t];
    }
    else
    {
        int a = 0;
        for (int x = t; x <= k/n; x++)
        {
            a += recursion(k-x, n-1, x);
        }

        return dp[k][n][t] = a;
    }
}


int main()
{
    int a, b;
    cin >> a >> b;
    cout << recursion(a, b, 1);
    return 0;
}
