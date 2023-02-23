#include<bits/stdc++.h>
using namespace std;

const int N = 2002;
int a, b;
int maze[N][N];
int visited[N][N];
int level[N][N];
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

bool isInside(pair<int, int>coord)
{
    int x = coord.first;
    int y = coord.second;
    if(x>=0 && x<a && y>=0 && y<b)
        return true;
    else
        return false;
}
bool isSafe(pair<int,int>coord)
{
    if(maze[coord.first][coord.second] == 0)
        return true;
    else
        return false;
}
void bfs(pair<int, int>src)
{
    queue<pair<int, int>> q;
    visited[src.first][src.second] = 1;
    level[src.first][src.second] = 0;
    q.push(src);
    while(!q.empty())
    {
        pair<int, int> head = q.front();
        q.pop();
        int x = head.first;
        int y = head.second;
        for (int i = 0; i < 4; i++)
        {
            int new_x = x + dx[i];
            int new_y = y + dy[i];
            pair<int, int> adj_node = {new_x, new_y};
            if(isInside(adj_node) && isSafe(adj_node) && visited[new_x][new_y]==0)
            {
                visited[new_x][new_y] = 1;
                level[new_x][new_y] = level[x][y] + 1;
                q.push(adj_node);
            }
            
        }
    }
}

int main()
{
    cout << "Started" << endl;
    cin >> a >> b;
    pair<int, int> src, dst;
    for (int i = 0; i < a; i++)
    {
        string input;
        cin >> input;
        for (int j = 0; j < b; j++)
        {
            if(input[j] == '#')
            {
                maze[i][j] = -1;
            }
            else if(input[j] == 'A')
            {
                src = {i, j};
            }
            else if(input[j] == 'B')
            {
                dst = {i, j};
            }
        }
    }
    cout <<dst.first<< "---->" << dst.second << endl;
    bfs(src);
    if(visited[dst.first][dst.second]==1)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    cout << "Length: " << level[dst.first][dst.second] << endl;

    // for (int i = 0; i < a; i++)
    // {
    //     for (int j = 0; j < b; j++)
    //     {
    //         cout << maze[i][j] << "\t";
    //     }
    //     cout << endl;
    // }
    // cout << endl;

    return 0;
}
/*

5 8
########
#.A#...#
#.##.#B#
#......#
########

*/