#include <iostream>
#include <string>
#include <unordered_map>

using std::string;
using std::unordered_map;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> charMap; // To store the last index of every character
        int maxLength = 0;
        int left = 0; // Left pointer of the sliding window
        
        for (int right = 0; right < s.length(); ++right) {
            char currentChar = s[right];
            
            // If the character is found in the map and is inside the current window
            if (charMap.find(currentChar) != charMap.end() && charMap[currentChar] >= left) {
                left = charMap[currentChar] + 1; // Move the left pointer to the right of the last occurrence
            }
            
            charMap[currentChar] = right; // Update the last index of the current character
            maxLength = std::max(maxLength, right - left + 1); // Calculate the max length
        }
        
        return maxLength;
    }
};

int main() {
    Solution sol;

    // Example 1
    string str1 = "abcabcbb";
    std::cout << "Input: " << str1 << "\nOutput: " << sol.lengthOfLongestSubstring(str1) << std::endl;

    // Example 2
    string str2 = "bbbbb";
    std::cout << "Input: " << str2 << "\nOutput: " << sol.lengthOfLongestSubstring(str2) << std::endl;

    // Example 3
    string str3 = "pwwkew";
    std::cout << "Input: " << str3 << "\nOutput: " << sol.lengthOfLongestSubstring(str3) << std::endl;

    return 0;
}
