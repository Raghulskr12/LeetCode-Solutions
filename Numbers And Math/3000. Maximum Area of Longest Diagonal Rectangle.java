class Solution {
    public int areaOfMaxDiagonal(int[][] dimensions) {
        int maxDiagonalSquared = Integer.MIN_VALUE; // track max diagonal length squared
        int maxArea = 0; // track area of rectangle with max diagonal

        // Traverse each rectangle
        for (int i = 0; i < dimensions.length; i++) {
            int length = dimensions[i][0];
            int width = dimensions[i][1];

            // Diagonal length squared = length^2 + width^2 (Pythagoras)
            int diagonalSquared = (length * length) + (width * width);

            // Area of rectangle = length × width
            int area = length * width;

            // Update if diagonal is bigger OR diagonal equal but area bigger
            if (diagonalSquared > maxDiagonalSquared || 
               (diagonalSquared == maxDiagonalSquared && area > maxArea)) {
                maxDiagonalSquared = diagonalSquared;
                maxArea = area;
            }
        }

        return maxArea;
    }
}
