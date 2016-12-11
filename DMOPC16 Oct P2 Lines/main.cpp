#include <bits/stdc++.h>

using namespace std;

vector<vector<int> >dp

struct line{
    int slope;
    int inter;
};

int main()
{
    int n, m;
    int t;
    cin >> t;
    bool ok = false;
    int c = t*(t-1)/2;

    vector<line> a(t);
    for (int x = 0; x < t; x++)
    {
        cin >> n >> m;
        a[x].slope = n;
        a[x].inter = m;
        for (int y = 0; y < x; y++)
        {
            if (a[x].slope == a[y].slope)
            {
                if (a[x].inter == a[y].inter)
                {
                    ok = true;
                    break;
                }
                else
                {
                    c--;
                }
            }
        }
        if (ok)
        {
            break;
        }
    }
    if (ok)
    {
        cout << "Infinity";
    }
    else
    {
        cout << c;
    }
    return 0;
}
