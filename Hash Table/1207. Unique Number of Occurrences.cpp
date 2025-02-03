class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> frequencyMap; // Stores the frequency of each element
        set<int> uniqueFrequencies; // Stores unique frequency counts

        // Count the occurrences of each element
        for (auto num : arr) {
            frequencyMap[num]++;
        }

        // Insert frequencies into the set
        for (auto entry : frequencyMap) {
            uniqueFrequencies.insert(entry.second);
        }    

        // If the number of unique frequencies matches the number of elements, return true
        return uniqueFrequencies.size() == frequencyMap.size();
    }
};
