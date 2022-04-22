class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
        while (low < high) {
            auto mid = low + (high - low) / 2;
            if (nums[mid] < nums[high])
                // the mininum is in the left part
                high = mid;
            else if (nums[mid] > nums[high])
                // the mininum is in the right part
                low = mid + 1;
        }

        return nums[low];
    }
};