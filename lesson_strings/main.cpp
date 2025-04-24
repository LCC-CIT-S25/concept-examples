#include <iostream>
#include <iomanip>

/*
 *
 * Limitation: only works for [0-20]
 * returns: "non" for any other value
 */
std::string romanNumeral(int num) {
    // numeral Look up table
    const std::string numeralLUT[] =
        {
        "",
        "I",
        "II",
        "III",
        "IV",
        "V",
        "VI",
        "VII",
        "VIII",
        "IX",
        "X",
        "XI",
        "XII",
        "XIII",
        "XIV",
        "XV",
        "XVI",
        "XVII",
        "XVIII",
        "XIX",
        "XX",
        };

    if (num >=0 && num <=20) {
        return numeralLUT[num];
    }
    return "non";
}

/*
 * Check if a string is a palindrome
 * "racecar"
 *  check if character values are identical
 */
bool isPalindrome(const std::string& str) {
    bool retVal = true;

    size_t len = str.size();
    for (int i=0; i < len/2; i++) {
        if (str[i] != str[len-1-i]) {
            retVal = false;
            break;
        }
    }

    return retVal;
}

/* find palindromic words in a sentence
 *
 */


int main() {
    if (false) {
        for (int i=-1; i < 22; i++) {
            std::cout << "numeral of " << std::setw(4) << i << " -> "
            << std::setw(5) << romanNumeral(i) << std::endl;
        }
    }

    if (true) {
        std::string palindromes[] =
            {
            "racecar",
            "step on no pets",
            "",
            "a",
            "AbA",
            "!12@21!",
            };
        std::string notPalindromic[] ={
        "CS161",
        "Hello world!",
        };

        std::cout << "true palindromes" << std::endl;
        for (auto& palindrome: palindromes) {
            std::cout << "testing " << palindrome << "  " <<
                isPalindrome(palindrome) << std::endl;
        }


        std::cout << "not palindromes" << std::endl;
        for (auto& test: notPalindromic) {
            std::cout << "testing " << test << "  " <<
                isPalindrome(test) << std::endl;

        }
    }

    return 0;
}