#include <iostream>
#include <climits> // For INT_MAX and INT_MIN

int reverse(int x) {
    int reversed = 0;
    while (x != 0) {
        int pop = x % 10;
        x /= 10;

        // Check for overflow/underflow conditions
        if (reversed > INT_MAX / 10 || (reversed == INT_MAX / 10 && pop > 7)) return 0;
        if (reversed < INT_MIN / 10 || (reversed == INT_MIN / 10 && pop < -8)) return 0;

        reversed = reversed * 10 + pop;
    }
    return reversed;
}

int main() {
    int x1 = 123;
    int x2 = -123;
    int x3 = 120;

    std::cout << "Input: " << x1 << " Output: " << reverse(x1) << std::endl;
    std::cout << "Input: " << x2 << " Output: " << reverse(x2) << std::endl;
    std::cout << "Input: " << x3 << " Output: " << reverse(x3) << std::endl;

    return 0;
}
