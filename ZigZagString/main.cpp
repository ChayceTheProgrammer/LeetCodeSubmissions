#include <iostream>
#include <vector>
#include <string>

/* Explaination
Edge Case:
If numRows is 1, the string is returned as is, because there's no zigzag pattern to form.

Initialization:
A std::vector<std::string> called rows is used to store the characters for each row.
The curRow variable keeps track of the current row we are filling.
The goingDown boolean variable indicates whether we are moving down or up in the zigzag pattern.

Filling the Rows:
We iterate over each character in the string s and append it to the appropriate row in rows.
If curRow is 0 or the last row (numRows - 1), we change the direction by toggling goingDown.
Depending on the direction (goingDown), we either move to the next row or the previous row.

Concatenation:
After all characters are placed in their respective rows, we concatenate all the rows to form the final result.

Output:
The main function demonstrates the usage of the convert function with the given examples. It prints the input and the corresponding output.*/

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
