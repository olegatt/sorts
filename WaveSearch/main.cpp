#include <iostream>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

const int wall = 9999;
const int block = -1;
const int N = 15;
int map[N][N];
vector<pair<int, int> > wave;


void ShowMap()
{
    system("cls");
    for (int i=0; i<N; ++i)
    {
        cout<< "\n";
        for (int j=0; j<N; ++j)
        {
            if (map[i][j] == wall)
                cout<< "[ + ]";
            else if (map [i][j] == block)
                cout<<"[   ]";
            else if (block && map[i][j] < 10)
                cout<<"[ "<<map[i][j]<<" ]";
            else cout<<"[ "<<map[i][j]<<"]";
        }
    }
}

void ShowMapWay(int a, int b)
{
    cout<<"\n ["<<a<<"]["<<b<<"] ="<<map[a][b];
}

void zapolnenie()
{
    for (int i=0; i<N; ++i)
        for (int j=0; j<N; ++j)
        {
            if (rand() % 7 == 0)
                map[i][j] = wall;
            else map [i][j] = block;
        }
    for (int i=0; i<N; ++i)
    {
        map[i][0] = wall;
        map[0][i] = wall;
        map[i][N-1] = wall;
        map[N-1][i] = wall;
    }
    vector<pair<int, int> > oldWave;
    oldWave.push_back(pair<int, int>(1,1));
    int nstep = 0;
    map[1][1] = nstep;
    const int dx[] = {0, 1, 0, -1};
    const int dy[] = {-1, 0, 1, 0};
    while (oldWave.size() > 0)
    {
        ++nstep;
        wave.clear();
        for (vector<pair<int, int> >::iterator i = oldWave.begin(); i != oldWave.end(); ++i)
        {
            for (int d=0; d<4; ++d)
            {
                int nx = i -> first + dx[d];
                int ny = i -> second + dy[d];
                if (map[nx][ny]==-1)
                {
                    wave.push_back(pair<int, int>(nx,ny));
                    map[nx][ny] = nstep;
                    ShowMap();
                    if (nx == N - 2 && ny == N-2)
                        goto done;
                }
            }
        }
        oldWave = wave;
    }
done:
    int x = N-2;
    int y = N-2;
    wave.clear();
    wave.push_back(pair<int, int>(x,y));
    while (map[x][y] != 0)
    {
        ShowMapWay(x,y);
        for (int dd = 0; dd<4; ++dd)
        {
            int nnx = x + dx[dd];
            int nny = y + dy[dd];
            if (map[x][y] - 1 == map[nnx][nny])
            {
                x=nnx;
                y=nny;
                wave.push_back(pair<int, int>(x,y));
                break;
            }
        }
    }
    ShowMapWay(x,y);
}

int main()
{
    zapolnenie();
    system("pause");
    return 0;
}
