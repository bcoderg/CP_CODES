

long long int merge(long long a[] , long long int l , long long int m, long long int r)
{
    long long int size=(r-l+1);
    vector<long long int>temp(size);
    long long int idx=0;
    long long int count=0; 

    long long int i=l , j=m+1; 
    while(i<=m && j<=r)
    {
        if(a[i]>a[j])
        {
            count+=(m-i+1);
            j++;
        }
        else
        {
            i++;
        }
    }

    i=l , j=m+1;
    while(i<=m && j<=r)
    {
        if(a[i]<a[j])temp[idx++]=a[i++];

        else temp[idx++]=a[j++];
    }

    while(i<=m)temp[idx++]=a[i++];
    while(j<=r)temp[idx++]=a[j++];

    idx=0;
    //make as sorted
    for(int i=l;i<=r;i++)
    {
        a[i]=temp[idx++];
    }
    
    return count;

}

long long int inv(long long a[], long long int l , long long int r)
{
    if(l>=r)return 0;

    long long int  m=l+(r-l)/2;

    long long int left_count=inv(a,l,m);
    long long int right_count=inv(a,m+1,r);
    long long int merge_count=merge(a,l,m,r);

    return (left_count+right_count+merge_count);
}

long long int inversionCount(long long a[], long long N)
    {
        // Your Code Here
        long long int ans=0;
        ans=inv(a,0,N-1);
        return ans;
    }
