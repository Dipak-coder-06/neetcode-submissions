class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> counts;
        for (int num : nums) {
            counts[num]++;
        }

        vector<pair<int, int>> freqPairs;
        for (auto const& [val, count] : counts) {
            freqPairs.push_back({count, val});
        }

        sort(freqPairs.rbegin(), freqPairs.rend());

        vector<int> ans;
        for (int i = 0; i < k; i++) {
            ans.push_back(freqPairs[i].second);
        }

        return ans;
    }
};