/*
 * @lc app=leetcode.cn id=2679 lang=cpp
 *
 * [2679] 矩阵中的和
 */

// @lc code=start
class Solution {
public:
    int matrixSum(vector<vector<int>>& nums) {
        int res = 0;
        int m = nums.size();
        int n = nums[0].size();
        for (int i = 0; i < m; i++) {
            sort(nums[i].begin(), nums[i].end());
        }
        for (int j = 0; j < n; j++) {
            int maxVal = 0;
            for (int i = 0; i < m; i++) {
                maxVal = max(maxVal, nums[i][j]);
            }
            res += maxVal;
        }
        return res;
    }
};
// @lc code=end

