#include<bits/stdc++.h>
#define pub push_back
using namespace std;
const int N = 1e5;
vector<int> adj_list[N];
int visited[N]={0};
int level[N];

void bfs(int src)
{
    queue<int>q;
    visited[src] = 1;
    level[src] = 0;
    q.push(src);
    while(!q.empty())
    {
        int head = q.front();
        q.pop();
        //cout << head << endl;
        for(int adj_node : adj_list[head])
        {
            if(visited[adj_node]==0)
            {
                level[adj_node] = level[head] + 1;
                q.push(adj_node);
                visited[adj_node] = 1;
            }
        }
    }
}

int main()
{

    cout << "started" << endl;
    int a, b;
    cin >> a >> b;
    for (int i = 0; i < b; i++)
    {
        int u, v;
        cin >> u >> v;
        adj_list[u].pub(v);
        adj_list[v].pub(u);
    }
    bfs(2);
    for (int i = 0; i < a; i++)
    {
        cout << i << "--->" << level[i] << endl;
    }
        return 0;
}

/*
Input:
4 6
0 1
0 2
1 2
2 0
2 3
3 3
Output:2 0 1 3


*/
