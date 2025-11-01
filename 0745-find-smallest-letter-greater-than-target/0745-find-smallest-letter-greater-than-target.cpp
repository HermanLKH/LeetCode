class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        size_t left = 0;
        size_t right = letters.size() - 1;
        size_t mid;

        while (left < right) {
            mid = left + (right - left) / 2;

            if (letters[mid] > target) {
                right = mid;
            }
            else {
                left = mid + 1;
            }
        }
        if (letters[right] > target) {
            return letters[right];
        }
        else{
            return letters[0];
        }
    }
};