class Solution {
public:
    bool isSelfDividing(int a) {
        int k = a;
        while (a != 0) {
            int rem = a % 10;
            if (rem == 0 || k % rem != 0) {
                return false;
            }
            a /= 10;
        }
        return true;
    }

    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> result;
        for (int i = left; i <= right; i++) {
            if (isSelfDividing(i)) {
                result.push_back(i);
            }
        }
        return result;
    }
};

// 🚀 0ms Runtime Solution! 🚀

/*
Intuition:
A self-dividing number is one that is divisible by each of its digits. 
The key challenge is handling zeros and ensuring the number is divisible by each of its non-zero digits.

Approach:
1. We iterate through the range `[left, right]` using a for loop.
2. For each number `i`, we call the `isSelfDividing` function.
3. In the `isSelfDividing` function, we check each digit of the number:
   - If any digit is `0`, we return `false`.
   - If the number `k` is not divisible by any of its digits, we also return `false`.
4. If all digits divide the number evenly, we return `true`.
5. If the number is self-dividing, we add it to the result vector.

Time complexity: O(n * d), where 'n' is the size of the range (i.e., `right - left + 1`) and 'd' is the average number of digits in the numbers checked.

Space complexity: O(1) for the computation, excluding the space used by the result vector, which grows with the number of self-dividing numbers found.
*/
