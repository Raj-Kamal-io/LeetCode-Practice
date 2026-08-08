class Solution {
    bool check(int n,long long mid,vector<int>&arr)
    {
        long long count=0;
        for(int i=0; i<arr.size(); i++)
        {
            count += (sqrt(mid/arr[i]));
        }
        if(count>=n) return true;
        else return false;
    }
public:
    long long repairCars(vector<int>& ranks, int cars) {
        long long l=1;
        long long sum=0;
        long long h = *min_element(ranks.begin(), ranks.end()) * 1LL * cars * cars;
       
        long long ans=h;
        while(l<=h)
        {
            long long mid=l+(h-l)/2;
            if(check(cars,mid,ranks))
            {
                ans=mid;
                h=mid-1;
            }else
            {
                l=mid+1;
            }
        }
        return ans;

    }
};