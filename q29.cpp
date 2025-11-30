// Little Vasya loves orange juice very much. That's why any food and drink in his kitchen necessarily contains orange juice. There are n drinks in his fridge, the volume fraction of orange juice in the i-th drink equals pi percent.

// One day Vasya decided to make himself an orange cocktail. He took equal proportions of each of the n drinks and mixed them. Then he wondered, how much orange juice the cocktail has.

// Find the volume fraction of orange juice in the final drink.

// Input
// The first input line contains a single integer n (1 ≤ n ≤ 100) — the number of orange-containing drinks in Vasya's fridge. The second line contains n integers pi (0 ≤ pi ≤ 100) — the volume fraction of orange juice in the i-th drink, in percent. The numbers are separated by a space.

// Output
// Print the volume fraction in percent of orange juice in Vasya's cocktail. The answer will be considered correct if the absolute or relative error does not exceed 10  - 4.

// Examples
// InputCopy
// 3
// 50 50 100
// OutputCopy
// 66.666666666667
// InputCopy
// 4
// 0 25 50 75
// OutputCopy
// 37.500000000000


#include <iostream>
#include <iomanip>
using namespace std;
int main() {
    int n;
    cin >> n;
    double totalPercentage = 0.0;
    for (int i = 0; i < n; ++i) {
        double p;
        cin >> p;
        totalPercentage += p;
    }
    double averagePercentage = totalPercentage / n;
    cout << fixed << setprecision(12) << averagePercentage << endl;
    return 0;
}
