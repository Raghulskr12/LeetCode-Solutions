class Solution {
public:
    // Merge two sorted halves of the array
    void merge(int low, int high, int mid, vector<int>& nums) {
        vector<int> temp;
        int left = low;
        int right = mid + 1;

        // Standard merge step of merge sort
        while (left <= mid && right <= high) {
            if (nums[left] <= nums[right]) {
                temp.push_back(nums[left]);
                left++;
            } else {
                temp.push_back(nums[right]);
                right++;
            }
        }

        // Copy remaining elements from left half
        while (left <= mid) {
            temp.push_back(nums[left]);
            left++;
        }

        // Copy remaining elements from right half
        while (right <= high) {
            temp.push_back(nums[right]);
            right++;
        }

        // Copy back the merged elements to original array
        for (int i = low; i <= high; i++) {
            nums[i] = temp[i - low];
        }
    }

    // Count reverse pairs where nums[i] > 2 * nums[j]
    int countReversePairs(int low, int high, int mid, vector<int>& nums) {
        int count = 0;
        int right = mid + 1;

        for (int left = low; left <= mid; left++) {
            while (right <= high && nums[left] > (long long)nums[right] * 2) {
                right++;
            }
            count += right - (mid + 1);
        }
        return count;
    }

    // Recursive merge sort that counts reverse pairs
    int mergeSortAndCount(int low, int high, vector<int>& nums) {
        if (low >= high) return 0;

        int mid = (low + high) / 2;
        int count = 0;

        count += mergeSortAndCount(low, mid, nums);
        count += mergeSortAndCount(mid + 1, high, nums);
        count += countReversePairs(low, high, mid, nums);
        merge(low, high, mid, nums);

        return count;
    }

    // Main function
    int reversePairs(vector<int>& nums) {
        return mergeSortAndCount(0, nums.size() - 1, nums);
    }
};
