#include <iostream>

bool isPalindrome(int num) {
    int originalNum = num;
    int reversedNum = 0;

    while (num > 0) {
        int remainder = num % 10;
        reversedNum = reversedNum * 10 + remainder;
        num /= 10;
    }

    return originalNum == reversedNum;
}

void printPalindromes(int n) {
    std::cout << "Palindrome numbers from 1 to " << n << " are:" << std::endl;
    
    for (int i = 1; i <= n; ++i) {
        if (isPalindrome(i)) {
            std::cout << i << " ";
        }
    }

    std::cout << std::endl;
}

int main() {
    int n;
    std::cout << "Enter a number (n): ";
    std::cin >> n;

    printPalindromes(n);

    return 0;
}
