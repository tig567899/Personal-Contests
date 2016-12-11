#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    int m;
    long long int k;
    int a;
    int b;
    cin >> n;
    cin >> m;
    cin >> k;
    vector <long long> difference(n+2, 0);
    for (int x = 0; x < m; x++)
    {
        cin >> a;
        cin >> b;
        difference[a]--;
        difference[b+1]++;
    }
    difference[1] += m;
    for (int x = 2; x < n+1; x++)
    {
        difference[x] += difference[x-1];
    }
    for (int x = 2; x < n+1; x++)
    {
        difference[x] += difference[x-1];
    }
    int ans = 999999;
    int s = 0;
    for (int t = 1; t < n+2; t++)
    {
        while (s <=t && (difference[t] - difference [s]) >= k )
        {
            ans = min (ans, t-s);
            s++;
        }
    }
    if (ans == 999999)
    {
        cout << -1;
    }
    else {
        cout << ans;
    }
}
