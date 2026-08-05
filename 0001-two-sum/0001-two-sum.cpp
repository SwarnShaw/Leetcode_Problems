class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        for (int i = 0, n = nums.size(); i < n; ++i) {
            if (auto it = map.find(target - nums[i]); it != map.end())
                return {i, it->second};
            else
                map[nums[i]] = i;
        }
        return {-1, -1};
    }
};