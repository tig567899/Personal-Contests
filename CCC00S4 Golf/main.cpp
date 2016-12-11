#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    int n, m, dist;
    bool win = false;
    queue<int> q;
    cin >> n >> m;
    vector<int> dp(n+1,99999999);
    dp[0] = 0;
    vector<int> clubs;
    for (int x = 1; x < m+1; x++)
    {
        cin >> dist;
        clubs.push_back(dist);
    }
    q.push(0);
    while(!q.empty())
    {
        if (q.front() == n)
        {
            win = true;
            break;
        }
        for (int t = 0; t < m; t++)
        {
            if (q.front()+clubs[t] < dp.size())
            {
                if (dp[q.front()]+1 < dp[q.front()+clubs[t]])
                {
                    dp[q.front()+clubs[t]] = dp[q.front()] + 1;
                    q.push(q.front()+clubs[t]);
                }
            }
        }
        q.pop();
    }
    if (win)
        cout << "Roberta wins in " << dp[n] <<" strokes.";
    else
        cout << "Roberta acknowledges defeat.";
    return 0;
}
