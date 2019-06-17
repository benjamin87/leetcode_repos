// https://leetcode.com/problems/length-of-last-word/description/
class Solution_58 {
    public int lengthOfLastWord(String s) {
        int last = 0;
        int cur = 0;
        for(int i = 0; i < s.length(); i++) {
            char ch = s.charAt(i);
            if(ch != ' ') {
                ++cur;
            }
            else if(cur != 0){
                last = cur;
                cur = 0;
            }
        }
        return cur > 0 ? cur : last;
    }

    public static void main(String args[]) { 
        Solution_58 s = new Solution_58();
        System.out.println(s.lengthOfLastWord("dv df"));
        System.out.println(s.lengthOfLastWord("a "));
        System.out.println(s.lengthOfLastWord("b   a    ")); 
    } 
}