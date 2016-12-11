#include <iostream>

using namespace std;

vector<int> dp(201, 9999999);

int findmin(vector<int> f)
{
    int minimum = 9999999;
    for (int x = 0; x < f.size(); x++)
    {
        minimum = min(minimum, f[x]);
    }
    return minimum;
}

int main()
{
    int s, n;
    int counter = 0;
    map<string, int> q;
    vector<int> f;
    cin >> s >> n;
    vector<string> a;
    int in;
    string t;
    for (int x = 0; x < n; x++)
    {
        cin >> t;
        cin >> in;
        q[t] = in;
        a.push_back(t);
    }
    dp[0] = q[a[0]];
    for(int x = 1; x < n; x++)
    {
        for (int y = 1; y < s; y++)
        {
            if (x-y < 0)
            {
                break;
            }
            else
            {
                if q[a[1]]
            }
        }
    }
    return 0;
}
