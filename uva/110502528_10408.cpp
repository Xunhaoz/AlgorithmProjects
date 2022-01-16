#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
//#include <memory.h>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <math.h>
#include <stack>
#include <string>
#define MINF 0x3f3f3f3f
using namespace std;
typedef long long LL;

const int MAXN = 200+10;
const int INF = 1e9;

struct Edge
{
    int from, to, cap;
};
vector<Edge> edges;
vector<int> G[MAXN*4];
int Dis[MAXN*4];
int a[MAXN*4], b[MAXN*4];
int n, m, s, t;

void AddEdge(int from, int to, int cap)
{
    edges.push_back(Edge{from, to, cap});
    edges.push_back(Edge{to, from, cap});
    G[from].push_back(edges.size()-2);
    G[to].push_back(edges.size()-1);
}

bool Bfs()
{
    memset(Dis, -1, sizeof(Dis));
    queue<int> que;
    que.push(s);
    Dis[s] = 0;
    while (!que.empty())
    {
        int u = que.front();
        que.pop();
        // cout << u << endl;
        for (int i = 0;i < G[u].size();i++)
        {
            Edge &e = edges[G[u][i]];
            if (e.cap > 0 && Dis[e.to] == -1)
            {
                Dis[e.to] = Dis[u]+1;
                que.push(e.to);
            }
        }
    }
    return Dis[t] != -1;
}

int Dfs(int u, int flow)
{
    if (u == t)
        return flow;
    int res = 0;
    for (int i = 0;i < G[u].size();i++)
    {
        Edge &e = edges[G[u][i]];
        if (e.cap > 0 && Dis[u]+1 == Dis[e.to])
        {
            // cout << "flow:" << e.from << ' ' << e.to << ' '<< endl;
            int tmp = Dfs(e.to, min(flow, e.cap));
            // cout << "flow:" << e.from << ' ' << e.to << ' ' << tmp << endl;
            e.cap -= tmp;
            flow -= tmp;
            edges[G[u][i]].cap += tmp;
            res += tmp;
            if (flow == 0)
                break;
        }
    }
    if (res == 0)
        Dis[u] = -1;
    return res;
}

int MaxFlow()
{
    int res = 0;
    while (Bfs())
    {
        res += Dfs(s, INF);
    }
    return res;
}

int main()
{
//    freopen("test.in", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    while (cin >> n >> m && n)
    {
        for (int i = 1;i <= n;i++)
            G[i].clear();
        edges.clear();
        s = 1, t = 2;
        int u, v, w;
        for (int i = 1;i <= m;i++)
        {
            cin >> u >> v >> w;
            AddEdge(u, v, w);
            a[i] = u, b[i] = v;
        }
        int res = MaxFlow();
        for (int i = 1;i <= m;i++)
        {
            if ((Dis[a[i]] >= 0 && Dis[b[i]] == -1) || (Dis[b[i]] >= 0 && Dis[a[i]] == -1))
                cout << a[i] << ' ' << b[i] << endl;
        }
        cout << endl;
    }

    return 0;
}
