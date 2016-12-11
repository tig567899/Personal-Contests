#include <iostream>

using namespace std;

int main()
{
    int n;
    int m;
    cin >> n >> m;
    cout << "Sun Mon Tue Wed Thr Fri Sat \n";
    for (int x = 1; x<n; x++)
        cout <<"    ";
    cout << "  ";
    for (int x = 1; x <= m; x++)
    {
        cout << x;
        n++;
        cout << " ";
        if (n > 7 && x != m)
        {
            cout << "\n";
            n = 1;
        }
        if (x <= 8)
        {
            cout << "  ";
        }
        else
        {
            cout << " ";
        }
    }
    return 0;
}
