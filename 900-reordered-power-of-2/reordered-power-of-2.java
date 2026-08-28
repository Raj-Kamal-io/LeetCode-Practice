class Solution {
    public boolean reorderedPowerOf2(int n) {
        int [] mp = new int[10];
        while(n> 0){
            mp[n % 10]++;
            n /= 10;
        }
        for(int i = 0; i <31; i++){
            int res = 1 << i;
            int[]mp1 = new  int[10];
            while(res > 0){
                mp1[res % 10]++;
                res /= 10;
            }
            if (Arrays.equals(mp , mp1)){
                return true;
            }
        }
        return false;
    }
}