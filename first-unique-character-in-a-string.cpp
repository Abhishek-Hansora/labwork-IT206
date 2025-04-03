#include <iostream>
#include <vector>

int firstUniqChar(std::string s) {
    std::vector<int> freq(26, 0);


    for (char c : s) {
        freq[c - 'a']++;
    }


    for (int i = 0; i < s.size(); i++) {
        if (freq[s[i] - 'a'] == 1) {
            return i;
        }
    }

    return -1; 
}

int main() {
    std::string s = "leetcode";
    std::cout << "First Unique Character Index: " << firstUniqChar(s) << std::endl;
    return 0;
}
