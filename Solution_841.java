import java.util.List;
import java.util.Stack;

// https://leetcode.com/problems/keys-and-rooms/description/
// DFS
class Solution_841 {

    public boolean canVisitAllRooms(List<List<Integer>> rooms) {
        boolean[] unlockRoom = new boolean[rooms.size()];
        Stack<Integer> keys = new Stack<>();
        keys.addAll(rooms.get(0));
        unlockRoom[0] = true;

        while(!keys.isEmpty()) {
            int nextToVisit = keys.pop();
            if(!unlockRoom[nextToVisit]) {
                keys.addAll(rooms.get(nextToVisit));
                unlockRoom[nextToVisit] = true;
            }
        }

        
        for(int i = 0; i < rooms.size(); i++) {
            if(!unlockRoom[i]) {
                return false;
            }
        }
        return true;
    }

    public static void main(String args[]) { 

    } 
}