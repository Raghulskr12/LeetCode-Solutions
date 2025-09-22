class Solution {
    public boolean canPlaceFlowers(int[] flowerbed, int flowersToPlant) {
        // If no flowers need to be planted, it's always possible
        if (flowersToPlant == 0) return true;

        // Special case: only one plot in the flowerbed
        if (flowerbed.length == 1) {
            if (flowerbed[0] == 1 && flowersToPlant == 0) return true;   // Already planted, no flowers needed
            else if (flowerbed[0] == 0 && flowersToPlant == 1) return true; // Empty and we need 1 flower
            else return false; // All other cases are not possible
        }

        // Check the first plot
        if (flowerbed[0] == 0 && flowerbed[1] == 0) {
            flowerbed[0] = 1;     // Plant a flower
            flowersToPlant--;
        }
        if (flowersToPlant == 0) return true;

        // Check the middle plots
        for (int i = 1; i < flowerbed.length - 1; i++) {
            if (flowersToPlant == 0) return true;
            // Plant only if current plot and adjacent plots are empty
            if (flowerbed[i - 1] == 0 && flowerbed[i] == 0 && flowerbed[i + 1] == 0) {
                flowerbed[i] = 1;
                flowersToPlant--;
            }
        }

        if (flowersToPlant == 0) return true;

        // Check the last plot
        if (flowerbed[flowerbed.length - 1] == 0 && flowerbed[flowerbed.length - 2] == 0) {
            flowerbed[flowerbed.length - 1] = 1;
            flowersToPlant--;
        }

        // Final check
        return flowersToPlant == 0;
    }
}
