class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> output(n - k + 1);

        deque<int> q;  // Store indices
        int l = 0, r = 0;

        while (r < n) {

            // Step 1: Remove smaller elements
            while (!q.empty() && nums[q.back()] < nums[r]) {
                q.pop_back();
            }

            // Step 2: Add current index
            q.push_back(r);

            // Step 3: Remove index outside window
            if (l > q.front()) {
                q.pop_front();
            }

            // Step 4: Store maximum
            if (r + 1 >= k) {
                output[l] = nums[q.front()];
                l++;
            }

            // Step 5: Move right
            r++;
        }

        return output;
    }
};