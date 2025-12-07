class Solution {
    public int countOdds(int low, int high) {
        
        // Total number of integers in the range [low, high]
        int totalRangeCount = high - low + 1;

        // If both ends are odd, the number of odd values increases by 1
        if (low % 2 == 1 && high % 2 == 1) {
            return (totalRangeCount / 2) + 1;
        }

        // Otherwise, exactly half of the numbers will be odd
        return totalRangeCount / 2;
    }
}
