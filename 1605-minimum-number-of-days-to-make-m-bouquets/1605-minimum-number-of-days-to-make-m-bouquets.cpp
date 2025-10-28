class Solution {
public:
    int canMakeBouquets(int dayWaited, vector<int>& bloomDay, int m, int k) {
        int flowersCollected = 0;
        int bouquetsMade = 0;

        for (int i = 0; i < bloomDay.size(); i++) {
            if (bloomDay[i] <= dayWaited) {
                // add 1 collected flower
                flowersCollected = flowersCollected + 1;
            }
            // if see unbloomed flower
            else {
                // reset flowers collected
                flowersCollected = 0;
            }
            // if k number of bloomed flowers collected
            if (flowersCollected == k) {
                // make 1 bouquet
                bouquetsMade = bouquetsMade + 1;
                // reset flowers collected
                flowersCollected = 0;
            }
            // if m bouquets are made -> true
            if (bouquetsMade == m) {
                return true;
            }
        }
        // after looping every flower, no enough bouquets are made -> false
        return false;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        // no enough flowers -> impossible to make enough bouquets
        if (bloomDay.size() < (long long) m * k) {
            return -1;
        }

        // initialize variables for binary search
        int minDay = 1;
        int maxDay = 1;
        int midDay;

        // loop over the array to get the maximum day we need to wait
        for (int b: bloomDay) {
            if (b > maxDay) {
                maxDay = b;
            }
        }

        // binary search to find minimum days wait to make m bouquets
        while (minDay < maxDay) {
            midDay = minDay + (maxDay - minDay) / 2;

            if (canMakeBouquets(midDay, bloomDay, m, k)) {
                maxDay = midDay;
            }
            else {
                minDay = midDay + 1;
            }
        }
        return maxDay;
    }
};