#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define nl "\n";
const int N = 0;


class SGTree
{
    vector<int>st;
public:
    SGTree(int n)
    {
        st.resize(4 * n + 1);
    }
    void build(int idx, int l, int r , vector<int>&v)
    {
        if (l > r)return;

        if (l == r)
        {
            st[idx] = v[l];
            return;
        }
        int mid = (l + r) / 2;

        build( (2 * idx) + 1 , l, mid, v);
        build( (2 * idx) + 2 , mid + 1, r, v);

        st[idx] = (st[(2 * idx) + 1] + st[(2 * idx) + 2]);
    }

    void update(int l , int r, int idx , int pos, int val , vector<int>&v)
    {
        //  if (l > pos || r < pos)return st[idx]; // not in ranges

        if (l == r)
        {
            v[pos] = val; // update in original array
            st[idx] = val;
            return;
        }

        int mid = (l + r) / 2;

        //within in left range
        if (pos <= mid)update( l, mid, (2 * idx) + 1 , pos , val, v);

        // in right range
        else update( mid + 1, r, (2 * idx) + 2 , pos , val , v);

        st[idx] = ( st[(2 * idx) + 1] + st[(2 * idx) + 2] );


    }



//range sum fine

    int rangesum(int l , int r, int idx , int a , int b ,  vector<int>&v )
    {
        // l r a b   || a b l r  ===> no overlap
        if (a > r || b < l)return 0;

        if (a <= l && r <= b)return st[idx];

        int mid = (l + r) / 2;

        int left = rangesum(l, mid, (2 * idx) + 1 , a, b , v );
        int right = rangesum(mid + 1, r, (2 * idx) + 2 , a, b , v);

        return (left + right);
        //return st[idx];
    }


};





void badhri() {

    int n, q; cin >> n >> q;

    SGTree sg1(n);

    vector<int>v(n);
    for (int i = 0; i < n; i++)cin >> v[i];

    sg1.build(0, 0, n - 1, v);

    while (q--)
    {
        int a, b, c; cin >> a >> b >> c;
        if (a == 1)
        {
            sg1.update(0, n - 1, 0 , b - 1, c, v);
        }
        else
        {
            // b ,c  = in range [a , b]

            int ans = sg1.rangesum(0, n - 1, 0, b - 1, c - 1, v);
            cout << ans << nl;
        }
    }

    //cout << nl;
}

signed main() {

    fast
    // int t; cin >> t;

    // while (t--) {
    badhri();
    //}
}


// Segment Tree COncepts , Questions

// STriver Tree CP sheet , LC Trees

// Difference Array Technique

// 1 Hour - Maths for CP

// clg subjects YOUTUBE





