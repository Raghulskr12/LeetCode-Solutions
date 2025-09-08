class Solution {
    public int duplicateNumbersXOR(int[] nums) {
        // Map to store frequency of each number
        Map<Integer, Integer> frequencyMap = new HashMap<>();
        
        // Count occurrences of each number
        for (int number : nums) {
            if (frequencyMap.containsKey(number)) {
                frequencyMap.put(number, frequencyMap.get(number) + 1);
            } else {
                frequencyMap.put(number, 1);
            }
        }
        
        int xorResult = 0;
        
        // Iterate over map entries to find numbers appearing exactly twice
        for (Map.Entry<Integer, Integer> entry : frequencyMap.entrySet()) {
            if (entry.getValue() == 2) {
                // XOR all numbers that appear exactly twice
                xorResult ^= entry.getKey();
            }
        }
        
        // Return the final XOR value
        return xorResult;
    }
}
