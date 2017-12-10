class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int n = nums.size(), max_all = 1, max_here = 1;
        if (n == 0) return 0;
        for(int i = 1; i < n; i++){
            if (nums[i] > nums[i-1]) max_here = max_here + 1;
            else max_here = 1;
            if (max_all < max_here) max_all = max_here;
        }
        return max_all;
    }
};
