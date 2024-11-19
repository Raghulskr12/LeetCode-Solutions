class Solution {
public:
    string categorizeBox(int length, int width, int height, int mass) {
        // Check if the box is both bulky and heavy
        if ((length >= 10000 || width >= 10000 || height >= 10000 || 
             (length >= 1000 && width >= 1000 && height >= 950)) && mass >= 100) {
            return "Both";
        }

        // Check if the box is bulky
        if (length >= 10000 || width >= 10000 || height >= 10000 || 
            (length >= 1000 && width >= 1000 && height >= 950)) {
            return "Bulky";
        }

        // Check if the box is heavy
        if (mass >= 100) {
            return "Heavy";
        }

        // If neither condition is met, categorize the box as neither
        return "Neither";
    }
};
