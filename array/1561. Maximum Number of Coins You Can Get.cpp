class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int totalCoins = 0;       // To store the maximum coins we can collect
        int size = piles.size();  // Number of piles

        // Sort the piles in descending order to access the largest values first
        sort(piles.begin(), piles.end(), greater<int>());

        // Start picking coins according to the strategy
        for (int i = 1; i < size; i++) {
            totalCoins += piles[i];  // Take the second-largest pile in each group of three
            i++;                     // Skip the smallest pile in the group
            size--;                  // Reduce the size to simulate one group being processed
        }

        return totalCoins;  // Return the total maximum coins collected
    }
};
