class Solution {
    public int maxFrequencyElements(int[] nums) {
        // Map to store the frequency of each number
        Map<Integer, Integer> frequencyMap = new HashMap<>();

        int maxFrequency = 0;   // Highest frequency found so far
        int maxFrequencyCount = 0; // Number of elements that have the highest frequency

        // Count the frequency of each number
        for (int num : nums) {
            frequencyMap.put(num, frequencyMap.getOrDefault(num, 0) + 1);
        }

        // Find the maximum frequency and how many numbers have it
        for (int frequency : frequencyMap.values()) {
            if (frequency > maxFrequency) {
                maxFrequency = frequency;   // Update max frequency
                maxFrequencyCount = 0;      // Reset count of elements with max frequency
            }
            if (frequency == maxFrequency) {
                maxFrequencyCount++;        // Count how many numbers have the max frequency
            }
        }

        // Each of these numbers contributes 'maxFrequency' times
        return maxFrequencyCount * maxFrequency;
    }
}
