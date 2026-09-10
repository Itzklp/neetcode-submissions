class Solution {
   public:
    int maxArea(vector<int>& heights) {
        int i = 0, j = heights.size() - 1;
        int area = 0;

        while (i < j) {
            int tmpArea = (j - i) * min(heights[i], heights[j]);
            area = max(area, tmpArea);

            if (heights[i] < heights[j]) {
                i++;
            } else if (heights[i] > heights[j]) {
                j--;
            } else {
                j--;
                i++;
            }
        }

        return area;
    }
};
