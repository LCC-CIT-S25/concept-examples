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
        "", "I", "II", "III",
        "IV", "V", "VI", "VII",
        "VIII", "IX", "X", "XI",
        "XII", "XIII", "XIV", "XV",
        "XVI", "XVII", "XVIII", "XIX",
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
 *  check if character values are identical forward and reverse
 */
bool isPalindrome(const std::string& str) {
    bool is_palindrome = true;

    //  0123456
    // "racecar"
    const int len = str.size();
    for (int i=0; i < len/2 && is_palindrome; i++) {
        if (str[i] != str[len - 1 - i]) {
            is_palindrome = false;
        }
    }

    return is_palindrome;
}

/* find palindromic words in a sentence
 *
 */

/*
 * make a string palindromic
 */
std::string mirrorString(const std::string & str) {
    std::string result = str;

    for (int i=str.size() - 2; i>=0; i--) {
        result.push_back(str[i]);
    }

    return result;
}

int main() {
    {
        std::string s1 = "hello";
        std::string s2 = "world";
        s1 += ' '; // s1="hello "
        s1 += s2; // s1="hello world"
        s1.push_back('!'); // We can also use this function to add a character s1="hello world!"
        s1[0] = toupper(s1[0]); //s1 = "Hello world!"
        std::cout << "result:" << s1 << std::endl;
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
            std::cout << "I fixed it " << mirrorString(test) << std::endl;

        }
    }

    if (false) {
        for (int i=-1; i < 22; i++) {
            std::cout << "numeral of " << std::setw(4) << i << " -> "
            << std::setw(5) << romanNumeral(i) << std::endl;
        }
    }

    return 0;
}