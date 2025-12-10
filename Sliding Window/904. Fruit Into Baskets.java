import java.util.HashMap;
import java.util.Map;

class Solution {
    public int totalFruit(int[] fruits) {
        int left = 0;
        int maxLength = 0;
        Map<Integer, Integer> freq = new HashMap<>();

        for (int right = 0; right < fruits.length; right++) {
            int rightFruit = fruits[right];
            freq.put(rightFruit, freq.getOrDefault(rightFruit, 0) + 1);

            while (freq.size() > 2) {
                int leftFruit = fruits[left];
                freq.put(leftFruit, freq.get(leftFruit) - 1);
                if (freq.get(leftFruit) == 0) {
                    freq.remove(leftFruit);
                }
                left++;
            }

            maxLength = Math.max(maxLength, right - left + 1);
        }

        return maxLength;
    }
}
