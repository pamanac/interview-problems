//Jump Game II

class Solution {
    public int max(int a, int b){ return a>b?a:b;}
    public int min(int a,int b){return a<b ? a:b;}

    public int jump(int[] nums) {
        int N = nums.length;
        int[] dp = new int[N];
        dp[0] = 0;
        for (int i = 1; i < N; i++)
            dp[i] = Integer.MAX_VALUE;

        for (int start = 0; start < N; start++) {
            int maxJump = nums[start];
            for (int jump = 1; jump <= maxJump; jump++) {
                if (start + jump < N) {
                    dp[start + jump] = min(dp[start] + 1, dp[start + jump]);
                }
            }
        }
        return dp[N - 1];
    }
}