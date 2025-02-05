class Solution {
public:
    vector<int> findPeaks(vector<int>& array) {
        vector<int> peaks;
        for (int index = 1; index < array.size() - 1; index++) {
            if (array[index - 1] < array[index] && array[index] > array[index + 1]) {
                peaks.push_back(index);
            }
        }
        return peaks;
    }
};

/*
Explanation:
- The function `findPeaks` takes a vector of integers `array` as input.
- It initializes an empty vector `peaks` to store the indices of the peak elements.
- The function iterates through the array from the second element to the second-to-last element.
- It checks if the current element is greater than its neighbors. If it is, the index of that element is added to the `peaks` vector.
- Finally, the function returns the vector containing the indices of all peak elements.
*/
