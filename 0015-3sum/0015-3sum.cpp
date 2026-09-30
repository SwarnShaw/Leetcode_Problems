class Solution {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        std::vector<std::vector<int>> result;
        int n = nums.size();
        if (n < 3) return result;

        std::sort(nums.begin(), nums.end());

        const int OFFSET = 100000;
        const int MAX_VAL = 200001;
        std::bitset<MAX_VAL> present;
        std::bitset<MAX_VAL> duplicates;

        for (int x : nums) {
            int idx = x + OFFSET;
            if (present.test(idx)) {
                duplicates.set(idx);
            } else {
                present.set(idx);
            }
        }

        for (int i = 0; i < n - 2; ++i) {
            if (nums[i] > 0) break;
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            for (int j = i + 1; j < n - 1; ++j) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;

                int target = -(nums[i] + nums[j]);
                if (target < nums[j]) break;

                int targetIdx = target + OFFSET;
                if (targetIdx >= 0 && targetIdx < MAX_VAL) {
                    if (target == nums[j]) {
                        if (duplicates.test(targetIdx)) {
                            if (target == nums[i]) {
                                int count = (nums[i + 2] == nums[i]);
                                if (count) result.push_back({nums[i], nums[j], target});
                            } else {
                                result.push_back({nums[i], nums[j], target});
                            }
                        }
                    } else if (present.test(targetIdx)) {
                        result.push_back({nums[i], nums[j], target});
                    }
                }
            }
        }

        return result;
    }
};