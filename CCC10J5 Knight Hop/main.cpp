#include <bits/stdc++.h>

using namespace std;

vector<vector<int> > dist(8,vector<int> (8, -1));

struct coord {
    int x;
    int y;
};

int main()
{
    int in1, in2;
    cin >> in1 >> in2;
    coord start;
    in1--;
    in2--;
    start.x = in1;
    start.y = in2;
    dist[in1][in2] = 0;
    int finalx, finaly;
    cin >> finalx >> finaly;
    finalx--;
    finaly--;
    queue<coord> q;
    q.push(start);
    //cout << finalx << " " << finaly << endl;
    while(!q.empty())
    {
        coord a = q.front();
        q.pop();
        int tempx = a.x;
        int tempy = a.y;
        coord b;
        //cout << a.x << " " << a.y << endl;
        if (tempx == finalx && tempy == finaly)
        {
            cout << dist[finalx][finaly] << endl;
            break;
        }
        if (tempy+1<8 && tempx+2 <8)
        {
            if (dist[tempx+2][tempy+1] == -1)
            {
                dist[tempx+2][tempy+1] = dist[tempx][tempy]+1;
                b.x = a.x +2;
                b.y = a.y +1;
                q.push(b);
            }
        }
        if (tempy-1 >=0 && tempx+2 <8)
        {
            if (dist[tempx+2][tempy-1] == -1)
            {
                dist[tempx+2][tempy-1] = dist[tempx][tempy]+1;
                b.x = a.x +2;
                b.y = a.y -1;
                q.push(b);
            }

        }
        if (tempy+1<8 && tempx-2 >=0)
        {
            if (dist[tempx-2][tempy+1] == -1)
            {
                dist[tempx-2][tempy+1] = dist[tempx][tempy]+1;
                b.x = a.x -2;
                b.y = a.y +1;
                q.push(b);
            }
        }

        if (tempy-1 >=0 && tempx-2 >=0)
        {
            if (dist[tempx-2][tempy-1] == -1)
            {
                dist[tempx-2][tempy-1] = dist[tempx][tempy]+1;
                b.x = a.x -2;
                b.y = a.y -1;
                q.push(b);
            }
        }
        if (tempy-2 >=0 && tempx-1 >=0)
        {
            if (dist[tempx-1][tempy-2] == -1)
            {
                dist[tempx-1][tempy-2] = dist[tempx][tempy]+1;
                b.x = a.x -1;
                b.y = a.y -2;
                q.push(b);
            }
        }
        if (tempy+2<8 && tempx-1 >=0)
        {
            if (dist[tempx-1][tempy+2] == -1)
            {
                dist[tempx-1][tempy+2] = dist[tempx][tempy]+1;
                b.x = a.x -1;
                b.y = a.y +2;
                q.push(b);
            }
        }
        if (tempy+2<8 && tempx+1 <8)
        {
            if (dist[tempx+1][tempy+2] == -1)
            {
                dist[tempx+1][tempy+2] = dist[tempx][tempy]+1;
                b.x = a.x +1;
                b.y = a.y +2;
                q.push(b);
            }
        }
        if (tempy-2 >=0 && tempx+1 <8)
        {
            if (dist[tempx+1][tempy-2] == -1)
            {
                dist[tempx+1][tempy-2] = dist[tempx][tempy]+1;
                b.x = a.x +1;
                b.y = a.y -2;
                q.push(b);
            }
        }
    }
    return 0;
}
