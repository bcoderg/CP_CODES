//add description

vector<vector<int>> floydWarshall(int v, vector<vector<int>> &edges)
{
    vector<vector<int>>ans(v , vector<int>(v , 1e8));
    // complete the function
    for (int i = 0; i < v; i++)ans[i][i] = 0;
    for (auto x : edges)
    {
        ans[x[0]][x[1]] = x[2];
    }

    for (int k = 0; k < v; k++)
    {
        for (int i = 0; i < v; i++)
        {
            for (int j = 0; j < v; j++)
            {

                if (ans[i][k] < 1e8 && ans[k][j] < 1e8 )
                {
                    ans[i][j] = min(ans[i][j] , ans[i][k] + ans[k][j]);
                }

            }
        }
    }
    return ans;
}








