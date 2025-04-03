#include <iostream>
#include <vector>
#include <unordered_set>

int longestConsecutive(std::vector<int>& nums) {
    std::unordered_set<int> numSet(nums.begin(), nums.end()); 
    int longest = 0;

    for (int num : numSet) {
        if (numSet.find(num - 1) == numSet.end()) {  
            int currentNum = num;
            int currentLength = 1;

            while (numSet.find(currentNum + 1) != numSet.end()) { 
                currentNum++;
                currentLength++;
            }

            longest = std::max(longest, currentLength); 
        }
    }

    return longest;
}

int main() {
    std::vector<int> nums = {100, 4, 200, 1, 3, 2};
    std::cout << "Longest Consecutive Sequence Length: " << longestConsecutive(nums) << std::endl;
    return 0;
}
