import java.util.HashMap;
import java.util.Map;


// https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
class Solution_3 {
    public int lengthOfLongestSubstring(String s) {
        int globalMax = 0;
        Map<Character, Integer> chMap = new HashMap<>();

        for(int i = 0, j = 0; j < s.length(); j++) {
            char ch = s.charAt(j);
            if(chMap.containsKey(ch)) {
                i = Math.max(chMap.get(ch) + 1, i);
            }
            
            chMap.put(ch, j);
            globalMax = Math.max(globalMax, j - i + 1);
            
        }
        return globalMax;
    }

    public static void main(String args[]) { 
        Solution_3 s = new Solution_3();
        System.out.println(s.lengthOfLongestSubstring("dvdf"));
        System.out.println(s.lengthOfLongestSubstring("abba"));
    } 
}