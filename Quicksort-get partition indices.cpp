//problem link
//https://mentorpick.com/code?cid=a805c39e-f169-4ec3-8e1c-11b7360a2740&cslug=beingzero-restart-2024&pid=ac9144d4-08f5-49cf-83cd-2cab78f8e81d&pslug=bz-quick-sort-get-partition-indices&courseId=null&sectionId=ebd6682e-cf62-4337-b292-e8602f8c3613&type=null

#define inti long long
class BeingZero {
public:
    int partition(vector<inti>&v , inti l , inti r)
    {
        if (l > r)return -1;

        //cout<<"start = "<<l<<" "<<r<<"\n";
        int size = v.size() - 1;
        if (l < 0 || l > size || r > size || r < 0)return -1;

        inti pivot = v[l];
        inti i = l , j = r;
        if (l == r)return -1;


        while (i < j)
        {
            while (i < r && v[i] <= pivot)i++;
            while (j > l && v[j] > pivot)j--;

            if (i <= j && i < r && j > l)
            {
                //cout<<"for l = "<<l<<" "<<r<<" "<<i<<" "<<j<<"\n";
                swap(v[i], v[j]);
            }
            else {
                break;
            }
        }

        // if(j>=l && j<=r && (v[j] != v[l]) )
        // {
        //cout<<"ret = "<<l<<" "<<r<<" "<<i<<" "<<j<<"\n ";
        swap(v[j] , v[l]);
        return j;
        //}

        return -1;
    }
    void qs(inti l , inti r , vector<inti>&v, vector<inti>&ans)
    {
        if (l >= r )return;

        inti pi = partition(v, l, r);
        //cout<<pi<<" ";
        if (pi != -1)
        {
            ans.push_back(pi);
            //for(auto x:v)cout<<x<<" ";
        }
        qs(l, pi - 1, v, ans);
        qs(pi + 1, r, v, ans);


    }
    vector<int> getPartitionIndices(vector<inti> &v) {
        // Write code here!
        vector<inti>ans;
        inti n = v.size();
        qs(0, n - 1, v, ans);
        vector<int>k;
        for (auto x : ans)
        {
            k.push_back((int)x);
        }
        return k;
    }
};
