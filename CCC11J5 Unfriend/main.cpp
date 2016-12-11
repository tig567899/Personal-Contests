#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> people (n+1,1);
    int a;
    for (int x = 1; x < n; x++)
    {
        cin >> a;
        people[x]++;
        people[a] *= people[x];
    }
    cout << people[n];
    return 0;
}
