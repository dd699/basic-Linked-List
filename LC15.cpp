class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {
                break;
            }
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            unordered_set<int> set;

            for (int j = i + 1; j < nums.size(); j++) {
                //注意i要加一
                if (j > i + 2 && nums[j] == nums[j - 1] && nums[j - 1] == nums[j - 2]) {
                    continue;
                }
                int target = 0 - nums[i] - nums[j];
                if (set.find(target) != set.end()) {
                    result.push_back({ nums[i],0 - nums[i] - nums[j],nums[j] });
                    set.erase(target);
                    //注意这里不是删nums【j】，看看set里面存的是什么
                }
                else {
                    set.insert(nums[j]);
                }

            }
        }
        return result;
    }
};