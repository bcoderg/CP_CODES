

int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
	// Write your code here
	// vector<vector<int>>dp(n+1 , vector<int>(w+1 , 0));
	vector<int>prev(w+1 , 0);

	for(int i=1;i<=n;i++)
	{
		for(int j=w;j>=0;j--)
		{
			if(weights[i-1]<=j)
			{
				prev[j]=max(values[i-1]+prev[j-weights[i-1]]  , prev[j]);
			}
			else
			{
				prev[j]=prev[j];
			}
		}
	}
	
	return prev[w];
}




//comp differences O(n*m) to O(n)
/*

class BeingZero{
	public:
		int solve(int S,int W[], int V[], int n){
		    //complete the given function
			int ans = 0; 

            //using O(n) space only 1 array 
            //at each j , we need the values to ut's left , i.e j-w[i-1] , 
            //so we can fill the array from right to left , and update the maximums ====> converting O(2n)--> O(n)

            vector<int>prev(S+1,0);
            for(int i=1;i<=n;i++)
                {
                    for(int j=S;j>=0;j--)
                        {
                            if(W[i-1]<=j)
                            {
                                prev[j]=max(prev[j]  , prev[j-W[i-1]] + V[i-1] );
                            }
                        }
                }
            return prev[S];
            
            //int dp[n+1][S+1];    O(n*m) space 2d 
            /*
            vector<vector<int>>dp(n+1 , vector<int>(S+1,0));
            for(int i=1;i<=n;i++)
                {
                    for(int j=1;j<=S;j++)
                        {
                            dp[i][j]=dp[i-1][j];
                            
                            if(W[i-1]<=j)
                            {
                                dp[i][j]=max(dp[i-1][j] , dp[i-1][j-W[i-1]] + V[i-1]);
                            }
};

*/
