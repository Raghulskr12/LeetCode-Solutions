class Solution {
public:
    // Function to determine the type of triangle based on side lengths
    // Takes a vector of three integers representing the sides of a triangle
    string triangleType(vector<int>& sides) {
        // Check if all three sides are equal for an equilateral triangle
        if (sides[0] == sides[1] && sides[0] == sides[2]) {
            return "equilateral";
        }
        
        // Verify if the sides can form a valid triangle using the triangle inequality theorem
        // Each side must be less than the sum of the other two sides
        if ((sides[0] + sides[1] > sides[2]) && 
            (sides[1] + sides[2] > sides[0]) && 
            (sides[0] + sides[2] > sides[1])) {
            
            // Check for isosceles triangle (exactly two sides are equal)
            if (sides[0] == sides[1] || sides[1] == sides[2] || sides[0] == sides[2]) {
                return "isosceles";
            }
            
            // If no sides are equal, it's a scalene triangle
            return "scalene";
        }
        
        // If the triangle inequality theorem fails, no valid triangle can be formed
        return "none";
    }
};