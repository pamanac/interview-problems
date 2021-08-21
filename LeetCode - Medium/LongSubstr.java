//Longest Substring without repeating chars

class Solution {
    public int max(int a, int b){
        return a > b ? a:b;
    }
    public int lengthOfLongestSubstring(String s) {
        HashMap<Character, Integer> memo = new HashMap<Character, Integer>();
        int maxLen = 0, start = -1;
        if(s.length() == 1)
            return 1;
        for(int i=0; i<s.length(); i++){
            if(memo.containsKey(s.charAt(i)))
                start = max(start, memo.get(s.charAt(i)));
            memo.put(s.charAt(i), i);
            maxLen = max(maxLen, i-start);
            
        }
        return maxLen;
    }
}