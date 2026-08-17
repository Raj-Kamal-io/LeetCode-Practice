class Solution {
public:

    int solve(int i, int target, vector<int>& nums,vector<vector<int>>& dp){
        if(target == 0) return 0;

        if(i ==nums.size()) return -1;

        if(dp[i][target] != -2)
            return dp[i][target];

        int notTake = solve(i + 1, target, nums, dp);

        int take = -1;

        if(nums[i] <= target) {
            int result = solve(i + 1, target - nums[i], nums, dp);

            if (result != -1)
                take = 1 + result;
        }

        return dp[i][target] = max(take, notTake);
    }
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        int n = nums.size();

        vector<vector<int>> dp(n, vector<int>(target+1 , -2));

        return solve(0 , target , nums , dp);
    }
};