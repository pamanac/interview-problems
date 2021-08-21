Longest Palindromic Substring
class Solution {
   public String longestPalindrome(String s) {
            int n = s.length();

            /*
            * False if the characters [char1][char2] don't match
            * True otherwise
            */
            boolean[][] dp = new boolean[n][n];

            int start = 0; int end=0; //These pointers are used to save the longest palindrome
       
            for(int i=0;i<n;i++){
                dp[i][i] = true; //Each character matches with itself
                if(i+1<n){
                    dp[i][i+1] = s.charAt(i)==s.charAt(i+1); //Check if next character matches
                    if(dp[i][i+1]){
                        start = i;
                        end = i+1;
                    }
                }
            }

            for(int j=2;j<n;j++) // start at 2 because [i][i] and [i][i+1] are already done above
                for(int i=0;i<j;i++)
                    if(j-i>1) {
                        if(s.charAt(i)!=s.charAt(j))
                            dp[i][j] = false;
                        else {
                            dp[i][j] = dp[i+1][j-1];
                            if(dp[i+1][j-1])
                                if(end-start<j-i){
                                    end=j;
                                    start=i;
                                }
                        }
                    }

            return s.substring(start, end+1);
        }
}