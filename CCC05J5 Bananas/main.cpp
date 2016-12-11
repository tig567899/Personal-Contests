#include <iostream>
#include <string>

using namespace std;

string checkmon (string t)
{
    bool n = true;
    while(n)
    {
        n = false;
        for (int x = 0; x < t.size(); x++)
        {
            if (x < t.size() - 2)
            {
                if (t.substr(x, 3) == "ANA")
                {
                    t.erase(t.begin()+x);
                    t.erase(t.begin()+x);
                    n = true;
                }
                else if(t.substr(x,3) == "BAS")
                {
                    t.erase(t.begin()+x);
                    t.erase(t.begin()+x+1);
                    n = true;
                }
            }
        }
    }
    return t;
}

int main()
{
    string a = "foobar";
    while (a != "X")
    {
        cin >> a;
        if (a == "X")
        {
            break;
        }
        else
        {
            if(checkmon(a) == "A")
            {
                cout << "YES \n";
            }
            else
            {
                cout << "NO \n";
            }
        }
    }
    return 0;
}
