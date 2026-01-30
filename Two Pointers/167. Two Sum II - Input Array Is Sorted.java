class Solution {
    public int[] twoSum(int[] numbers, int target) {

        // Left pointer starts from beginning
        int leftPointer = 0;

        // Right pointer starts from end
        int rightPointer = numbers.length - 1;

        // Result array to store 1-based indices
        int[] result = new int[2];

        // Default values if no solution is found
        result[0] = -1;
        result[1] = -1;

        // Continue until pointers meet
        while (leftPointer < rightPointer) {

            // Calculate current sum
            int currentSum = numbers[leftPointer] + numbers[rightPointer];

            // If sum is greater than target, move right pointer left
            if (currentSum > target) {
                rightPointer--;
            }
            // If sum is smaller than target, move left pointer right
            else if (currentSum < target) {
                leftPointer++;
            }
            // Pair found
            else {
                // Problem requires 1-based indexing
                result[0] = leftPointer + 1;
                result[1] = rightPointer + 1;
                break;
            }
        }

        return result;
    }
}

