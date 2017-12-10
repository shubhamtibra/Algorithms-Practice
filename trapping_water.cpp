// Trapping water problem: Leetcode
class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() == 0) return 0;
        int max_all = -1, m_index;
        for(int i = 0; i < height.size(); i++){
            if (height[i] > max_all){
                max_all = height[i];
                m_index = i;
            }
        }
        int sum = 0;
        max_all = -1;
        for(int i = 0; i < m_index; i++){
            if (max_all != -1 && height[i] < max_all){
                sum += max_all - height[i];
            }
            max_all = max(max_all, height[i]);
        }
        max_all = -1;
        for(int i = height.size()-1; i > m_index; i--){
            if (max_all != -1 && height[i] < max_all){
                sum += max_all - height[i];
            }
            max_all = max(max_all, height[i]);
        }
        return sum;
    }
};
