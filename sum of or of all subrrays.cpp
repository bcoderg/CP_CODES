#include <bits/stdc++.h>
using namespace std;

//submit in other , put in github
//sum of or of all subrrays

class BeingZero {
public:
    long long solve(int a[], int n) {
        long long ans = 0;

        int total_subarrays = (n * (n + 1)) / 2;
        for (int bit = 0 ; bit < 64; bit++)
        {
            int c = 0;
            int count = 0;
            for (int i = 0; i < n; i++)
            {
                int val = a[i];
                if (val & (1 << bit))
                {
                    int k = (c * (c + 1)) / 2;

                    count += (k);
                    c = 0;
                }
                else
                {
                    c++;
                }
            }
            int k = (c * (c + 1)) / 2;
            count += (k);

            int rem = total_subarrays - count;
            ans += (rem * (1 << bit) );
        }



        return ans;
    }
};
