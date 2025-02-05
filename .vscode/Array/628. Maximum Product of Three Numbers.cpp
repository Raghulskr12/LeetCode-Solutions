class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int largest = INT_MIN, secondLargest = INT_MIN, thirdLargest = INT_MIN;  // Top three largest numbers
        int smallest = INT_MAX, secondSmallest = INT_MAX;  // Two smallest numbers for negative products

        // Traverse through the array to identify the largest and smallest numbers
        for (int i = 0; i < nums.size(); i++) {
            // Update the largest, second largest, and third largest values
            if (nums[i] > largest) {
                thirdLargest = secondLargest;
                secondLargest = largest;
                largest = nums[i];
            } else if (nums[i] > secondLargest) {
                thirdLargest = secondLargest;
                secondLargest = nums[i];
            } else if (nums[i] > thirdLargest) {
                thirdLargest = nums[i];
            }

            // Update the smallest and second smallest values
            if (nums[i] < smallest) {
                secondSmallest = smallest;
                smallest = nums[i];
            } else if (nums[i] < secondSmallest) {
                secondSmallest = nums[i];
            }
        }

        // Calculate the two possible maximum products and return the larger one
        int productWithLargest = largest * secondLargest * thirdLargest;  // Top three largest numbers
        int productWithSmallest = largest * smallest * secondSmallest;   // Combination of largest and two smallest

        return max(productWithLargest, productWithSmallest);
    }
};
