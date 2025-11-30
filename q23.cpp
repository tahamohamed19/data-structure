// It seems like the year of 2013 came only yesterday. Do you know a curious fact? The year of 2013 is the first year after the old 1987 with only distinct digits.

// Now you are suggested to solve the following problem: given a year number, find the minimum year number which is strictly larger than the given one and has only distinct digits.

// Input
// The single line contains integer y (1000 ≤ y ≤ 9000) — the year number.

// Output
// Print a single integer — the minimum year number that is strictly larger than y and all it's digits are distinct. It is guaranteed that the answer exists.

// Examples
// InputCopy
// 1987
// OutputCopy
// 2013
// InputCopy
// 2013
// OutputCopy
// 2014

#include <iostream>
using namespace std;

bool hasDistinctDigits(int year) {
    bool digits[10] = {false};
    while (year > 0) {
        int digit = year % 10;
        if (digits[digit]) {
            return false;
        }
        digits[digit] = true;
        year /= 10;
    }
    return true;
}
int main() {
    int y;
    cin >> y;
    while (true) {
        y++;
        if (hasDistinctDigits(y)) {
            cout << y << endl;
            break;
        }
    }
    return 0;
}