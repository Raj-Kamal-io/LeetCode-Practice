class Solution {
public:
    int minSubarray(vector<int>& nums, int p){

        long long total = 0;
        for(int x : nums){
            total += x;
        }
        int rem = total % p;
        if(rem == 0){
            return 0;
        }
        unordered_map<int, int> mp;
        mp[0] = -1;
        long long prefix = 0;
        int ans = INT_MAX;

        for(int i = 0; i < nums.size(); i++){

            prefix = (prefix + nums[i]) % p;

            int target = (prefix - rem + p) % p;

            if(mp.find(target) != mp.end()){
                ans = min(ans, i - mp[target]);
            }
            mp[prefix] = i;
        }
        if (ans == nums.size() || ans == INT_MAX){
            return -1;
        }
        return ans;
    }
};