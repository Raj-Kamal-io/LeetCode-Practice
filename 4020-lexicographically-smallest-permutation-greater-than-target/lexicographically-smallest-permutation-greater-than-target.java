class Solution {
    public String lexGreaterPermutation(String s, String target) {

        int n = s.length();
        int[] freq = new int[26];
        for(char ch : s.toCharArray()) {
            freq[ch - 'a']++;
        }

        StringBuilder ans = new StringBuilder();
        for(int i = 0; i < n; i++) {

            int curr = target.charAt(i) - 'a';

            if(freq[curr] > 0) {
                ans.append(target.charAt(i));
                freq[curr]--;

            }else {

                for(int c = curr + 1; c < 26; c++) {

                    if(freq[c] > 0) {

                        ans.append((char) ('a' + c));
                        freq[c]--;
                        addRemaining(ans, freq);

                        return ans.toString();
                    }
                }
                break;
            }
        } 

        while(ans.length() > 0) {
            char removed = ans.charAt(ans.length() - 1);
            ans.deleteCharAt(ans.length() - 1);

            freq[removed - 'a']++;

            int pos = ans.length();
            int curr = target.charAt(pos) - 'a';

            for(int c = curr + 1; c < 26; c++) {

                if(freq[c] > 0) {

                    ans.append((char) ('a' + c));
                    freq[c]--;
                    addRemaining(ans, freq);

                    return ans.toString();
                }
            }
        }
        return "";
    }
    private void addRemaining(StringBuilder ans, int[] freq) {

        for(int i = 0; i < 26; i++) {

            while(freq[i] > 0) {
                ans.append((char) ('a' + i));
                freq[i]--;
            }
        }
    }
}