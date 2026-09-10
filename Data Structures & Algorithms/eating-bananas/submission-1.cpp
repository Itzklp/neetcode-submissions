class Solution {
   public:
    bool fun(vector<int>& piles, int mid, int h) {
        int time = 0;

        for (int i : piles) {
            time += (i + mid - 1) / mid;

            if (time > h) {
                return false;
            }
        }

        return time <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        int ans = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (fun(piles, mid, h)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};
