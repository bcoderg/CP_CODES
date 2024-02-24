#include <bits/stdc++.h>

//modify this
for (auto x : edges)
{
    int u = x[0] , v = x[1] , wt = x[2];

    if (reach[v])
    {

        if (dist[u] + wt < dist[v])
        {
            dist[v] = dist[u] + wt;
        }
    }
}
}


//for negative cycle check , relax again
for (auto x : edges)
{
    int u = x[0] , v = x[1] , wt = x[2];

    if (reach[v])
    {

        if (dist[u] + wt < dist[v])
        {
            return { -1};
            dist[v] = dist[u] + wt;
        }
    }
}






//check for negative cycle by 1 more relaxation
for (int node = 0; node < v; node++)
{
    if (reach[node])
    {
        for (auto x : adj[node])
        {

            int  v = x.first , wt = x.second;
            if (dist[node] + wt < dist[v])
            {
                return { -1};
            }
        }
    }
}


for (int i = 0; i < dist.size(); i++)
{
    if (dist[i] == 1000000000000)dist[i] = 1000000000;

    ans.push_back((int)dist[i]);
}

// return dist;
return ans;
}

vector<int> findDistance(int v, vector<vector<int>> &edges, int q)
{
    // complete the function
    vector<vector<pair<int, int>>>adj(v + 1, vector<pair<int, int>>());

    for (auto x : edges)
    {
        int u = x[0] , vv = x[1] , w = x[2];


    };