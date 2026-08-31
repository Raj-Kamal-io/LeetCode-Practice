class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxprod = nums[0];
        int minprod = nums[0];

        int ans = nums[0];

        for(int i = 1; i < nums.size(); i++){
            int num = nums[i];

            if(num<0){
                swap(maxprod , minprod);
            }
            maxprod = max(num, maxprod * num);
            minprod = min(num, minprod * num);
            ans = max(ans, maxprod);
        }
        return ans;
    }
};