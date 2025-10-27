class Solution {
public:
    int canFinishBananas(int eatSpeed, vector<int>& piles, int availableHour) {
        int totalHour = 0;  // total hours used (must < available hours)
        int pileHour = 0;  // hours used to finish one pile
        int eatenBananas = 0;  // number of eaten bananas of a pile
        int i = 0;  // index of current pile eating

        // loop through all piles of bananas
        for (int pile: piles) {
            // calculate the hours needed to finish this pile of bananas
            pileHour = (pile + eatSpeed - 1) / eatSpeed;
            // accummulate total hours of eating bananas
            totalHour = totalHour + pileHour;

            // if total hours exceeds the available hours -> false
            if (totalHour > availableHour) {
                return false;
            }
        }
        // if loop through all bananas without excedding available hours -> true
        return true;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int maxEatSpeed = 0;
        int minEatSpeed = 1;
        int midEatSpeed;

        for (int pile: piles) {
            if ((long long) maxEatSpeed + pile > 1e9) {
                maxEatSpeed = 1e9;
                break;
            }
            else {
                maxEatSpeed = maxEatSpeed + pile;
            }
        }

        while (minEatSpeed < maxEatSpeed) {
            midEatSpeed = minEatSpeed + (maxEatSpeed - minEatSpeed) / 2;

            if (canFinishBananas(midEatSpeed, piles, h)) {
                maxEatSpeed = midEatSpeed;
            }
            else {
                minEatSpeed = midEatSpeed + 1;
            }
        }
        return maxEatSpeed;
    }
};