#include <cctype>
#include <iostream>
#include <string>

int main() {
    std::cout << "=== Password Strength Checker v1.1 ===\n";
    std::cout << "=== Is Your Password Safe? ===\n";

    std::cout << "Enter a password: ";

    std::string password;
    std::getline(std::cin, password);

    bool hasUpper = false, hasLower = false, hasDigit = false, hasSymbol = false;
    for (unsigned char c : password) {
        if (std::isupper(c)) hasUpper = true;
        else if (std::islower(c)) hasLower = true;
        else if (std::isdigit(c)) hasDigit = true;
        else if (std::ispunct(c)) hasSymbol = true;
    }

    int score = 0;
    if (password.length() >= 8) score++;
    if (password.length() >= 12) score++;
    if (hasUpper) score++;
    if (hasLower) score++;
    if (hasDigit) score++;
    if (hasSymbol) score++;

    std::string rating = "Weak";
    if (score >= 5) rating = "Strong";
    else if (score >= 3) rating = "Okay";

    std::cout << "Score: " << score << " / 6 (" << rating << ")\n";
    if (!hasSymbol) std::cout << "Tip: add a symbol like ! or #\n";
    if (password.length() < 12) std::cout << "Tip: try 12 or more characters\n";

    return 0;
}
