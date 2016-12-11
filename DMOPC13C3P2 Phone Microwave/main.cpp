#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int months[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int n = 0;
    cin >> n;
    cin.ignore(1, '\n');
    string i;
    getline(cin,i);
    string a = i.substr(0,4);
    int y = atoi(a.c_str());
    a = i.substr(5,2);
    int m = atoi(a.c_str());
    a = i.substr(9,2);
    int d = atoi(a.c_str());
    a = i[12]+i[13];
    int h = atoi (a.c_str());
    a = i[14]+i[15]+i[16]+i[17]+i[18]+i[19];
    while (true)
    {
        if (n>months[m+1]*24)
        {
            n -= months[m+1]*24;
            m--;
        }
        else
        {
            break;
        }
        if (m==0)
        {
            m = 12;
            y--;
        }
    }
    while (true)
    {
        if (n > 24)
        {
            d--;
            n-=24;
        }
        else{
            break;
        }
        if (d == 0)
        {
            m--;
            d = months[m+1];
            if (m==0)
            {
                m = 12;
                y--;
            }
        }
    }
    h -= n;
    if (h < 0)
    {
        h += 24;
        d--;
        if (d == 0)
        {
            m--;
            d = months[m+1];
            if (m==0)
            {
                m = 12;
                y--;
            }
        }
    }
    cout << y << "/";
    if (m < 10)
    {
        cout << 0 << m << "/";
    }
    else
    {
        cout << m << "/";
    }
    if (d < 10)
    {
        cout << 0 << d << "/";
    }
    else
    {
        cout << d << "/ ";
    }
    if (h < 10)
    {
        cout << 0 << h;
    }
    else
    {
        cout << h;
    }
    cout << a;
    return 0;
}
