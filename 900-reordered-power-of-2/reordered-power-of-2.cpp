class Solution {
public:
    bool reorderedPowerOf2(int n) {
        unordered_map<int, int> mp;
        while(n > 0) {
            mp[n % 10]++;
            n /= 10;
        }
        for(int i = 0; i < 31; i++) {
            int res = 1 << i;
            unordered_map<int, int> mp1;
            while(res > 0){
                mp1[res % 10]++;
                res /= 10;
            }
            if (mp1 == mp)
                return true;
        }
        return false;
    }
};