class Solution 
public:
    void quickSort(vector<int>& arr, int low, int high) {
        if (low < high) {
            // Get the correct position of the pivot element
            int pivotIndex = partition(arr, low, high);
            
            // Recursively sort elements before & after the pivot
            quickSort(arr, low, pivotIndex - 1);
            quickSort(arr, pivotIndex + 1, high);
        }
    }

private:
    int partition(vector<int>& arr, int low, int high) {
        int pivot = arr[low]; // Choosing the first element as pivot
        int left = low + 1;   // Start pointer from the next element
        int right = high;     // Start pointer from the end

        while (left <= right) {
            // Find an element larger than the pivot on the left
            while (left <= right && arr[left] <= pivot) {
                left++;
            }

            // Find an element smaller than the pivot on the right
            while (left <= right && arr[right] > pivot) {
                right--;
            }

            // Swap elements if left index is still smaller than right index
            if (left < right) {
                swap(arr[left], arr[right]);
            }
        }

        // Place pivot in its correct position
        swap(arr[low], arr[right]);

        // Return pivot's final position
        return right;
    }
};
