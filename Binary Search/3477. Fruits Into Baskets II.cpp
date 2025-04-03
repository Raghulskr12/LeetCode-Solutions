class Solution {
    public:
        int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
            int placedFruits = 0;
            
            // Try placing each fruit in a suitable basket
            for (int i = 0; i < fruits.size(); i++) {
                for (int j = 0; j < baskets.size(); j++) {
                    if (baskets[j] >= fruits[i]) { // If the basket can hold the fruit
                        placedFruits++;
                        baskets[j] = -1; // Mark basket as used
                        break;
                    }
                }
            }
            
            // Debug output for remaining basket states (optional)
            for (int basket : baskets) {
                cout << basket;
            }
            
            // Return the number of fruits that couldn't be placed
            return fruits.size() - placedFruits;
        }
    };
    