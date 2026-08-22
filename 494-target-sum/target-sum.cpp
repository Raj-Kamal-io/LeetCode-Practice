class Solution {
    int ans = 0;
    void solve(vector<int>& nums, int target, int i, int curr,int n) {

        if(i == n){
            if(curr == target)
            ans++;
            return;
            
        }

        solve(nums, target, i + 1, curr + nums[i], n);
        solve(nums, target, i + 1, curr - nums[i], n);
    }

public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = 0;
        solve(nums, target, 0, 0 , n);
        return ans;
    }
};