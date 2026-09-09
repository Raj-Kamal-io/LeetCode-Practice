class Solution {
public:
    vector<int> divisibilityArray(string word, int m) {
        vector<int> ans;
        long long n = word.size();
        long long rem = (word[0] - '0')% m;

        if(rem == 0){
            ans.push_back(1);
        } else {
            ans.push_back(0);
        }

        for(int i = 1; i<n; i++){
            rem *= 10;
            rem += ((word[i] - '0') % m);
            rem %= m;

            if(rem == 0){
                ans.push_back(1);
            } else {
                ans.push_back(0);
            }
        }
        return ans;
    }
};