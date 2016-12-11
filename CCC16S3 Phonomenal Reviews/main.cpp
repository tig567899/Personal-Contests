#include <bits/stdc++.h>

using namespace std;

vector<vector<int> > adj(100001);
vector<bool> pho (100001, false);
vector<int> distances(100002, -1);
vector<int> blank (100002, -1);

void DFS(int u, int t)
{
    distances[u] = t;
    for (int v = 0; v < adj[u].size(); v++)
    {
        if (distances[adj[u][v]] == -1)
        {
            DFS(adj[u][v], t+1);
        }
    }
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    int tempn = n;
    int in1, in2;
    bool pruned = false;
    tempn--;
    for (int x = 0; x < m; x++)
    {
        cin>> in1;
        pho[in1] = true;
    }
    for(int x = 0; x< n-1; x++)
    {
        cin >> in1 >> in2;
        adj[in1].push_back(in2);
        adj[in2].push_back(in1);
    }
    while (!pruned)
    {
        pruned = true;
        for (int x = 0; x <n; x++)
        {
            if (adj[x].size() == 1 && !pho[x])
            {
                int b = adj[x][0];
                adj[x].erase(adj[x].begin());
                for (int y = 0; y < adj[b].size(); y++)
                {
                    if (adj[b][y] == x)
                    {
                        adj[b].erase(adj[b].begin()+y);
                        break;
                    }
                }
                tempn--;
                pruned = false;
            }
        }
    }
//    cout << "AdjList: " << endl;
//    for (int x = 0; x < n; x++)
//    {
//        cout << x << ": ";
//        for (int y = 0; y < adj[x].size(); y++)
//        {
//            cout << adj[x][y] << " ";
//        }
//        cout << endl;
//    }
    int z;
    for (int x = 0; x < n; x++)
    {
        if (adj[x].size() > 0)
        {
            z = x;
            break;
        }
    }
    DFS(z, 0);
    int maxthing = -1;
    int maxpos = -1;
    for (int x = 0; x < n; x++)
    {
        if (distances[x] >maxthing)
        {
            maxthing = distances[x];
            maxpos = x;
        }
    }
    distances = blank;
    distances[maxpos] = 0;
    DFS(maxpos,0);
    for (int x = 0; x < n; x++)
    {
//        cout << distances[x] << " ";
        if (distances[x] > maxthing)
        {
            maxthing = distances[x];
            maxpos = x;
        }
    }
//    cout << endl;
//    cout << "TempN: " << tempn << endl;
//    cout << "Maxthing: " << maxthing << endl;
    cout << 2*tempn - maxthing;
    return 0;
}
