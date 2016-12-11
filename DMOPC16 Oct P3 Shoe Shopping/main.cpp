#include <bits/stdc++.h>

using namespace std;

vector<double> dp(10001, 99999999);
vector<double>shoes;
int n;

double find3min(double a, double b, double c)
{
    if (a>=b)
    {
        if (b>c)
        {
            return a+b;
        }
        else
        {
            return a+c;
        }
    }
    else
    {
        if (a<=c)
        {
            return b+c;
        }
        else
        {
            return a+b;
        }
    }
}

double recursion(int L)
{

    if (L == shoes.size())
    {
        return dp[L] = 0;
    }
    else if (dp[L] != 99999999)
    {
        return dp[L];
    }
    else if (L == shoes.size()-1)
    {
        return dp[L] = shoes[L];
    }
    else if (L == shoes.size()-2)
    {
        return dp[L] = shoes[L] + shoes[L+1] - min(shoes[L], shoes[L+1])/2;
    }
    else
    {
        dp[L] = min(min(shoes[L] + shoes[L+1] - min(shoes[L], shoes[L+1])/2 + recursion(L+2), find3min(shoes[L],shoes[L+1],shoes[L+2])+recursion(L+3)),shoes[L]+recursion(L+1));
        return dp[L];
    }
}

int main()
{
    double in;
    cin >> n;
    for (int x = 0; x < n; x++)
    {
        cin >> in;
        shoes.push_back(in);
    }
    double r = recursion(0);
    cout << recursion(0);
    if (r == int(r))
    {
        cout << ".0";
    }
    return 0;
}
