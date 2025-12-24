class Solution {
    public int minimumBoxes(int[] apple, int[] capacity) {

        // Step 1: Calculate the total number of apples
        int totalApples = 0;
        for (int i = 0; i < apple.length; i++) {
            totalApples += apple[i];
        }

        // Step 2: Sort the box capacities in ascending order
        Arrays.sort(capacity);

        int usedCapacity = 0;   // Total capacity used so far
        int boxCount = 0;       // Number of boxes used

        // Step 3: Use boxes starting from the largest capacity
        for (int i = capacity.length - 1; i >= 0; i--) {

            usedCapacity += capacity[i]; // Add current box capacity
            boxCount++;                  // One more box is used

            // Step 4: Check if all apples can be stored
            if (usedCapacity >= totalApples) {
                return boxCount;
            }
        }

        // This return is safe due to problem constraints
        return boxCount;
    }
}
