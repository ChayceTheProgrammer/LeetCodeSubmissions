#include <iostream>
#include <vector>
#include <string>

std::string convert(const std::string& s, int numRows) {
    if (numRows == 1) return s;

    std::vector<std::string> rows(std::min(numRows, int(s.size())));
    int curRow = 0;
    bool goingDown = false;

    for (char c : s) {
        rows[curRow] += c;
        if (curRow == 0 || curRow == numRows - 1) goingDown = !goingDown;
        curRow += goingDown ? 1 : -1;
    }

    std::string result;
    for (const std::string& row : rows) {
        result += row;
    }

    return result;
}

int main() {
    std::string s1 = "PAYPALISHIRING";
    int numRows1 = 3;
    std::cout << "Input: " << s1 << ", numRows = " << numRows1 << "\n";
    std::cout << "Output: " << convert(s1, numRows1) << std::endl; // Output: "PAHNAPLSIIGYIR"

    std::string s2 = "PAYPALISHIRING";
    int numRows2 = 4;
    std::cout << "Input: " << s2 << ", numRows = " << numRows2 << "\n";
    std::cout << "Output: " << convert(s2, numRows2) << std::endl; // Output: "PINALSIGYAHRPI"

    std::string s3 = "A";
    int numRows3 = 1;
    std::cout << "Input: " << s3 << ", numRows = " << numRows3 << "\n";
    std::cout << "Output: " << convert(s3, numRows3) << std::endl; // Output: "A"

    return 0;
}
