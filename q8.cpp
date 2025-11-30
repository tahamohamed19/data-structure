// Little Petya loves presents. His mum bought him two strings of the same size for his birthday. The strings consist of uppercase and lowercase Latin letters. Now Petya wants to compare those two strings lexicographically. The letters' case does not matter, that is an uppercase letter is considered equivalent to the corresponding lowercase letter. Help Petya perform the comparison.

// Input
// Each of the first two lines contains a bought string. The strings' lengths range from 1 to 100 inclusive. It is guaranteed that the strings are of the same length and also consist of uppercase and lowercase Latin letters.

// Output
// If the first string is less than the second one, print "-1". If the second string is less than the first one, print "1". If the strings are equal, print "0". Note that the letters' case is not taken into consideration when the strings are compared.

// Examples
// Input
// aaaa
// aaaA
// Output
// 0
// Input
// abs
// Abz
// Output
// -1
// Input
// abcdefg
// AbCdEfF
// Output
// 1


#include <iostream>
#include <string>
using namespace std;
int main() {
    string str1, str2;
    cin >> str1 >> str2;
    for (size_t i = 0; i < str1.length(); ++i) {
        char ch1 = tolower(str1[i]);
        char ch2 = tolower(str2[i]);
        if (ch1 < ch2) {
            cout << -1 << endl;
            return 0;
        } else if (ch1 > ch2) {
            cout << 1 << endl;
            return 0;
        }
    }
    cout << 0 << endl;
}