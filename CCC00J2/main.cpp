#include <iostream>
#include <string>
#include <sstream>

using namespace std;

bool checkstring(string a)
{
    for (int x = 0; x < a.size(); x++)
    {
        if (a[x] == '1' || a[x] == '8' || a[x] == '0')
        {
            if (a[a.size()-x-1] != a[x])
            {
                return false;
            }
        }
        else if (a[x] == '6')
        {
            if (a[a.size()-x-1] != '9')
            {
                return false;
            }
        }
        else if (a[x] == '9')
        {
            if (a[a.size()-x-1] != '6')
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }
    return true;
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int counter = 0;
    int m;
    int n;
    cin >> m >> n;
    stringstream b;
    string t;
    for(int x = m; x <=n; x++)
    {
        b << x;
        t = b.str();
        if (checkstring(t))
        {
            counter++;
        }
        b.str("");
    }
    cout << counter;
    return 0;
}
