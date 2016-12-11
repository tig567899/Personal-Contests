#include <iostream>

using namespace std;

int main()
{
    int a;
    cin >> a;
    bool t;
    int y, m, d;
    for (int x = 0; x < a; x++)
    {
        cin >> y;
        if (2007 - y > 18)
        {
            t = true;
            cin >> m >> d;
        }
        else if (2007 - y < 18)
        {
            t = false;
            cin >> m >> d;
        }
        else
        {
            cin >> m;
            if (m > 2)
            {
                t = false;
                cin >> d;
            }
            else if (m == 1)
            {
                cin >> d;
                t = true;
            }
            else
            {
                cin >> d;
                if (d > 27)
                {
                    t = false;
                }
                else if (d <= 27)
                {
                    t = true;
                }
            }
        }
        if (t)
        {
            cout << "Yes \n";
        }
        else
        {
            cout << "No \n";
        }
    }
    return 0;
}
