#include <bits/stdc++.h>

using namespace std;

vector<int> dp(10000, 0);
vector<vector<int> > park(10000);

int recursion(int a)
{
    if (a == 0)
    {
        return 1;
    }
    else if (dp[a] != 0)
    {
        return dp[a];
    }
    else
    {
        for (int x = 0; x < park[a].size(); x++)
        {
            dp[a] += recursion(park[a][x]);
        }
        return dp[a];
    }
}

int main()
{
    int n, in1 = -1, in2 = -1;
    cin >> n;
    park.resize(n);
    while (1)
    {
        cin >> in1 >> in2;
        if (in1 == 0)
        {
            break;
        }
        else
        {
            park[in2-1].push_back(in1-1);
        }
    }
    dp[0] == 1;
    cout << recursion(n-1);
    return 0;
}
