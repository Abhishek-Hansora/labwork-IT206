#include <iostream>
#include <unordered_map>
#include <vector>

std::vector<int> twoSum(std::vector<int>& nums, int target) {
    std::unordered_map<int, int> hashMap; 
    for (int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i];
        if (hashMap.find(complement) != hashMap.end()) {
            return {hashMap[complement], i};
        }
        hashMap[nums[i]] = i;
    }
    return {};
}

int main() {
    std::vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    std::vector<int> result = twoSum(nums, target);
    std::cout << "Indices: " << result[0] << ", " << result[1] << std::endl;
    return 0;
}
