#include <cctype>
#include <iostream>
#include <string>

int main() {
    std::cout << "=== Password Strength Checker ===\n";
    std::cout << "Enter a password: ";

    std::string password;
    std::getline(std::cin, password);

    bool hasUpper = false, hasLower = false, hasDigit = false;
    for (unsigned char c : password) {
        if (std::isupper(c)) hasUpper = true;
        else if (std::islower(c)) hasLower = true;
        else if (std::isdigit(c)) hasDigit = true;
    }

    int score = 0;
    if (password.length() >= 8) score++;
    if (hasUpper) score++;
    if (hasLower) score++;
    if (hasDigit) score++;

    std::cout << "Score: " << score << " / 4\n";
    return 0;
}
