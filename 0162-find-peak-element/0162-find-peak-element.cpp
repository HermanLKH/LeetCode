class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if (nums.size() == 1) {
            return 0;
        }
        size_t left = 0;
        size_t right = nums.size() - 1;
        size_t mid = left + (right - left) / 2;

        if (nums[right] > nums[right - 1]) {
            return right;
        }
        else if (nums[left] > nums[left + 1]) {
            return left;
        }

        while (left < right) {
            if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1]) {
                return mid;
            }
            else if (nums[mid] < nums[mid - 1]) {
                mid -= 1;
            }
            else if (nums[mid] < nums[mid + 1]) {
                mid += 1;
            }
        }
        return mid;
    }
};