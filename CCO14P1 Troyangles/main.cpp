#include <bits/stdc++.h>

using namespace std;
int counter = 0;

int find3min(int a, int b, int c)
{
    if (a >= b && b >= c)
    {
        return c;
    }
    else if (a >= b)
    {
        return b;
    }
    else if (a >= c)
    {
        return c;
    }
    else
    {
        return a;
    }
}

int main()
{
    string in;
    int n;
    cin >> n;
    vector<vector<char> > grid (n, vector<char>(n,'.'));
    for (int x = 0; x < n; x++)
    {
        cin >> in;
        for (int y = 0; y < n; y++)
        {
            grid[x][y] = in[y];
        }
    }
    vector<vector<int> > dp(n, vector<int>(n, 0));
    for (int x = n-1; x >= 0; x--)
    {
        for (int y = 0; y < n; y++)
        {
            if (x == n-1)
            {
                if (grid[x][y] == '#')
                {
                    dp[x][y] = 1;
                    counter++;
                }
            }
            else if (grid[x][y] == '#')
            {
                if (y == 0 || y == n-1)
                {
                    dp[x][y] = 1;
                    counter++;
                }
                else
                {
                    dp[x][y] = find3min(dp[x+1][y-1], dp[x+1][y], dp[x+1][y+1])+1;
                    counter+= dp[x][y];
                }
            }
        }
    }
    cout << counter;
    return 0;
}
