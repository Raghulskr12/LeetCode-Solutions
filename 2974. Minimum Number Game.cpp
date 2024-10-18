class Solution {
public:
    vector<int> numberGame(vector<int>& numbers) {
        sort(numbers.begin(), numbers.end());
        for (int index = 0; index < numbers.size() - 1; index++) {
            int temp = numbers[index];
            numbers[index] = numbers[index + 1];
            numbers[index + 1] = temp;
            index++;
        }
        return numbers;
    }
};

/*
Explanation:
- The function `numberGame` takes a vector of integers `numbers` as input.
- It first sorts the vector in ascending order.
- Then, it swaps each pair of adjacent elements in the sorted vector.
- Finally, it returns the modified vector with the adjacent elements swapped.
*/
