class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = numBottles; // Initialize the answer with the initial bottles
        
        while (numBottles >= numExchange) {
            int newBottles = numBottles / numExchange; // Bottles we can get after exchange
            ans += newBottles; // Add these new bottles to our answer
            numBottles = newBottles + (numBottles % numExchange); // Remaining bottles after exchange
        }
        
        return ans;
    }
};
