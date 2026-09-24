class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int ones = 0;

        for(int x : nums){
            if (x == 1)
                ones++;
        }

        int n=nums.size();
        int cnt = 0;
        int ans = 0;

        for(int i = 0; i < n + ones - 1; i++){
            if(nums[i % n] == 1)
                cnt++;
            if(i >= ones){
                if (nums[(i - ones) % n] == 1)
                    cnt--;
            }
            ans = max(ans, cnt);
        }

        return ones - ans;
    }
};