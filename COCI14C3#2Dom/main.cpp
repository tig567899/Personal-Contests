#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n,m,p;
    cin >> n >> m >> p;
    vector <int> hate (0);
    vector <int> like (0);
    vector <bool> covered (m,0);
    int h, l;
    for (int x = 0; x <n; x++)
    {
        cin >> l >> h;
        if (!covered[h-1])
        {
            hate.push_back(h);
            like.push_back(l);
            covered[h-1] = true;
        }
    }
    for (int x = 0; x < m; x++)
    {
        covered[x] = 0;
    }
    int ans = -1;
    vector <bool> reached (m+1, 0);
    reached[p] = 1;
    queue <int> q;
    q.push(p);
    while (!q.empty())
    {
        for(int x = 0; x <n; x++)
        {
            if (hate[x] == q.front())
            {
                q.push(like[x]);
                reached[hate[x]] == true;
                break;
            }
        }
        q.pop();
        if (q.front()== p)
        {
            ans = -1;
            break;
        }
        ans++;
    }
    cout << ans;
    return 0;
}
