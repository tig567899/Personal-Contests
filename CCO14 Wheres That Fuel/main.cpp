#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n, p;
    cin >> n >> p;
    vector <int> fuel (n+1,0);
    vector <int> costs (n+1,0);
    vector <bool> visited (n+1,0);
    int z = 0;
    int planets = 0;
    visited[p] = 1;
    int a, b;
    int inv = 0;
    for (int x = 0; x < n; x++)
    {
        cin >> a >> b;
        fuel[x] = a;
        costs[x] = b;
        cout << x << "\n";
    }
    inv += fuel[p];
    queue<int> q;
    q.push(p);
    int left = n;
    while (!q.empty())
    {
        inv += fuel[q.front()];
        inv -= costs[q.front()];
        q.pop();
        if (left != 0 && z == 0)
        {
            z = 1;
            for (int x = 1; x < n+1; x++)
            {
                if (visited[x] || inv < costs[x])
                {
                    continue;
                }
                else if (fuel[x] < costs[x])
                {
                    visited[x] = true;
                    left --;
                    continue;
                }
                else
                {
                    q.push(x);
                    visited[x] = true;
                    left--;
                    planets++;
                    z = 0;
                }
            }
        }
    }
    cout << inv << "\n";
    cout << planets << "\n";
    return 0;
}
