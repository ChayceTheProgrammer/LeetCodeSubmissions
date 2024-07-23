#include <iostream>
#include <string>

// Function to expand around center and return the longest palindrome length and start index
std::pair<int, int> expandAroundCenter(const std::string& s, int left, int right) {
    while (left >= 0 && right < s.size() && s[left] == s[right]) {
        left--;
        right++;
    }
    return {left + 1, right - left - 1};
}

std::string longestPalindrome(const std::string& s) {
    if (s.empty()) return "";

    int start = 0, maxLength = 1;

    for (int i = 0; i < s.size(); ++i) {
        // Odd length palindromes
        auto [left1, len1] = expandAroundCenter(s, i, i);
        if (len1 > maxLength) {
            start = left1;
            maxLength = len1;
        }

        // Even length palindromes
        auto [left2, len2] = expandAroundCenter(s, i, i + 1);
        if (len2 > maxLength) {
            start = left2;
            maxLength = len2;
        }
    }

    return s.substr(start, maxLength);
}

int main() {
    std::string s1 = "babad";
    std::string s2 = "cbbd";

    std::cout << "Input: " << s1 << "\nOutput: " << longestPalindrome(s1) << std::endl;
    std::cout << "Input: " << s2 << "\nOutput: " << longestPalindrome(s2) << std::endl;

    return 0;
}
