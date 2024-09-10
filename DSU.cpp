#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);


class UFDS{
    vector<int>rank,size,par; ///use basd on scenario 
        public:
    UFDS(int n){
        par.resize(n+1);
        rank.resize(n+1);
        size.resize(n+1);
        for(int i=0;i<=n;i++){
            par[i]=i;
            rank[i]=0; //all ranks 0 initially
            size[i]=1; //all are of size 1
        }
    }

        int find(int u){
            if(u==par[u])return u;

            //path compression 
            return par[u]=find(par[u]);
        }

        void join(int u , int v){
            int pu=find(u);
            int pv=find(v);
            if(pu==pv) return;//already connected

            if(rank[pu]>rank[pv]){
                par[pv]=pu;
                size[pu]+=size[pv];
            }
            else if(rank[pu]<rank[pv]){
                par[pu]=pv;
                size[pv]+=size[pu];
            }
            else{
                par[pv]=pu;
                rank[pu]++;
                size[pu]+=size[pv];
            }
            // if rank is same===> rank[pu]++
            // in all cases do size[pu]+=size[pv] type to maintain  size of that component
        }
};



void badhri(){

UFDS ufds(7);
ufds.join(1,2);
ufds.join(2,3);
ufds.join(4,5);
ufds.join(7,6);
ufds.join(5,6);

if(ufds.find(3)==ufds.find(7)){
    cout<<"YES";
}
else{
    cout<<"NO";
}

cout<<"\n";

ufds.join(3,7);


if(ufds.find(3)==ufds.find(7)){
    cout<<"YES";
}
else{
    cout<<"NO";
}



}

signed main(){

    fast
    int t=1;
 
   // cin>>t;
    
    while(t--){
        badhri();
    }
}