class Solution {

    static int solve(int[] nums , int target , int s , int e){
        if(s>e) return -1;

        int mid = (s+e)/2;
        if(nums[mid] == target) return mid;
        else if(nums[mid]> target) e = mid-1;
        else s = mid+1;

        return solve(nums , target , s , e);

    }
    public int search(int[] nums, int target) {
        int s = 0;
        int e = nums.length-1;
       int ans = solve(nums , target , s, e);

       return ans;
    }
}