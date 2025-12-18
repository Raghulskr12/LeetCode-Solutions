class Solution {
    public int numOfSubarrays(int[] arr, int k, int threshold) {

        // Stores the count of subarrays whose average >= threshold
        int count = 0;

        // Pointer indicating the start of the sliding window (offset by 1)
        int left = 1;

        // Pointer indicating the next element to enter the window
        int right = k;

        // Stores the sum of elements in the current window
        int windowSum = 0;

        // Calculate the sum of the first window (index 0 to k-1)
        for (int index = 0; index < k; index++) {
            windowSum += arr[index];
        }

        // Check if the average of the first window meets the threshold
        if ((windowSum / k) >= threshold) {
            count++;
        }

        // Slide the window across the array
        while (right < arr.length) {

            // Remove the element that goes out of the window
            // (left - 1 represents the previous window's starting index)
            windowSum -= arr[left - 1];

            // Add the new element entering the window
            windowSum += arr[right];

            // Check if the current window's average meets the threshold
            if ((windowSum / k) >= threshold) {
                count++;
            }

            // Move the window forward
            left++;
            right++;
        }

        // Return the total count of valid subarrays
        return count;
    }
}
