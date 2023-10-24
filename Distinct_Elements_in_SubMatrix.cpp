//Distinct Element Queries in Sub Matrix 
//https://mentorpick.com/code?cid=b9262c58-b8ca-4948-9989-0a7f6cbbfec6&cslug=bz-coding-marathon-1&pid=7c71f7ac-49db-4e5b-b41a-19566246f0b2&pslug=bz-distinct-ele-queries-in-submatrix&courseId=null&sectionId=undefined&type=null
//https://www.codechef.com/problems/RECTQUER


#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define nl "\n";
const int N=0;
void badhri(){
int n;cin>>n;
vector<vector<int>>v(n , vector<int>(n,0) );

int r=n , c=n;

//int freq[r][c][11]; 

//or 

//freq elements values till 10 , so k=11 
//k = max value in matrix+1

vector<vector<vector<int>>>freq(n , vector<vector<int>>(n , vector<int>(11,0)));


for(int i=0;i<n;i++){
   for(int j=0;j<n;j++)
   {
   	cin>>v[i][j];
   	freq[i][j][v[i][j]]++;
   }
}

for(int i=0;i<n;i++)
{
	for(int j=1;j<n;j++)
	{
		for(int k=0;k<11;k++)
		{
			freq[i][j][k]+=(freq[i][j-1][k]);
		}
		//cout<<"\n";
	}
}

for(int j=0;j<n;j++)
{
	for(int i=1;i<n;i++)
	{
		for(int k=0;k<11;k++)
		{
			freq[i][j][k]+=(freq[i-1][j][k]);
		}
		//cout<<"\n";
	}
}




//row wise & col wise prefix





int q;cin>>q;
while(q--)
{
	int a,b,c,d;cin>>a>>b>>c>>d; 
	a--;b--;c--;d--;

	int ans=0;
	for(int k=1;k<11;k++)
	{

		int cnt=( (freq[c][d][k] ) );

		if(a-1>=0){
			cnt-=( freq[a-1][d][k]  ) ;
		}

		if(b-1>=0){
			cnt-=( (freq[c][b-1][k] ) );
		}

		if(a-1>=0 && b-1>=0)
		{
			cnt+=( freq[a-1][b-1][k] );
		}


		if(cnt>0)
		{
			ans+=1;
		}

	}
	cout<<ans<<"\n";
}



/*
PRINT AND CHECK 

for(int i=0;i<n;i++)
{
	for(int j=0;j<n;j++)
	{
		for(int k=1;k<11;k++)
		{
			cout<<freq[i][j][k]<<" ";
		}
		cout<<"\n";
	}
}
*/




cout<<nl;

}

signed main(){

    fast
    // int t;cin>>t;
    
    // while(t--){
        badhri();
    //}
}

