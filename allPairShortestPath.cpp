#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<vector<int>>dist;
vector<vector<pair<int, int>>>adj;
vector<vector<int>>edges;
bool neg_cycle = false;
int ans = LLONG_MAX;

//floydWarshall giving TLE as it's N^3
/*
void floydWarshall(int n)
{
    int ans = LLONG_MAX;
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            if(dist[i][i]<0)
            {
                cout<<"-inf";return;
            }
            for (int j = 1; j <= n; j++)
            {
                if (dist[i][k] != 1e18 && dist[k][j] != 1e18)
                {
                    dist[i][j] = min(dist[i][j] , dist[i][k] + dist[k][j]);

                    if (i != j)
                    {
                        ans = min(dist[i][j] , ans);
                    }
                }
            }
        }
    }

    bool neg_cycle = false;
    //negative cycle check
    for (int i = 1; i <= n; i++)
    {
        if (dist[i][i] < 0)
        {
            neg_cycle = true; break;
        }
    }


    if (neg_cycle)cout << "-inf";

    else
    {
        // for (int i = 1; i <= n; i++)
        // {
        //     for (int j = 1; j <= n; j++)
        //     {
        //         if (i != j)
        //         {
        //             ans = min(dist[i][j] , ans);
        //         }
        //     }
        // }

        cout << ans;
    }

}
*/

void bellmanford(int s , int v)
{

    vector<int>dist(v + 1, 1e18);
    dist[s] = 0;
    for (int i = 0; i < v - 1; i++) // keep relaxing edges for n-1 times
    {
        //modify this
        for (auto x : edges)
        {
            int u = x[0] , v = x[1] , wt = x[2];
            //cout << u << " " << v << " " << wt << "\n";

            if (dist[u] + wt < dist[v])
            {
                dist[v] = dist[u] + wt;
            }
        }
    }

    //for negative cycle check , relax again
    for (auto x : edges)
    {
        int u = x[0] , v = x[1] , wt = x[2];
        if (dist[u] + wt < dist[v])
        {
            neg_cycle = true;
            return;
        }
    }
}


void djkistras(int s , int v)
{
    vector<int>dist(v + 1, 1e12);
    dist[s] = 0;
    priority_queue< pair<int, int> , vector<pair<int, int>> , greater<pair<int, int>> >pq;
    pq.push({0, s});

    while (!pq.empty())
    {
        auto cur = pq.top(); pq.pop();
        int node = cur.second;
        int cur_distance = cur.first;

        for (auto x : adj[node])
        {
            int vertex = x.first;
            int weight = x.second;

            if (dist[vertex] > cur_distance + weight)
            {
                dist[vertex] = cur_distance + weight;

                //check for minimum
                if (vertex != s)
                {
                    ans = min(ans , dist[vertex]);
                }
                pq.push({ cur_distance + weight , vertex});
            }
        }
    }
}


signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--)
    {
        int n, m; cin >> n >> m;
        //adjacency matrix
        //dist.assign(n + 1 , vector<int>(n + 1 , 1e18) );
        //adjacency list
        neg_cycle = false;
        ans = LLONG_MAX;
        adj.assign(n + 1 , vector<pair<int, int>>());

        for (int i = 0; i < m; i++)
        {
            int u, v, wt; cin >> u >> v >> wt;
            //dist[u][v] = min(dist[u][v] , wt);
            edges.push_back({u, v, wt});
            adj[u].push_back({v, wt});
        }

        //APP1
        //floydWarshall(n); - TLE

        //APP2 - first bellmanford - for negative check , then Djkistra on all vertices
        bellmanford(1, n);
        if (neg_cycle)
        {
            cout << "-inf";
        }
        else
        {
            for (int i = 1; i <= n; i++)
            {
                djkistras(i, n);
            }
            cout << ans;
        }

        cout << "\n";
        edges.clear();
    }
}

