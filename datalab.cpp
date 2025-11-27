#include <iostream>
using namespace std ;
#include <cmath>;

int main(){
    // Q1
    // The Fibonacci sequence of numbers is known: F1 = 1; F2 = 1; Fn+1 = Fn + Fn-1, for n>1. You have to find S - the sum of the first K Fibonacci numbers.
    // Input
    // First line contains natural number K (0<K<41).
    // Output
    // First line should contain number S.

    // Sample Input
    // 5
    // Sample Output
    // 12    


    // Answer:
    int k;
    int S = 0;
    int a = 1, b = 1;
    int c = a + b;

    cout << "Enter the value of K: ";
    cin >> k;
    for (int i = 1; i <= k; i++){
        if (i == 1 || i == 2){
            S += 1;
        }
        else{
            
            S += c;
            a = b;
            b = c;
        }
    }

    cout << "The sum of the first " << k << " Fibonacci numbers is: " << S << endl;






    // Q2
    // You are given natural numbers a and b. Find a^b-b^a.
    // Input
    // Input contains numbers a and b (1≤a,b≤100).
    // Output
    // Write answer to output.

    // Sample Input
    // 2 3
    // Sample Output
    // -1    



    // Answer:
    int a, b;
    cout << "Enter the value of a: ";
    cin >> a;
    cout << "Enter the value of b: ";
    cin >> b;

    int ans = (pow(a, b)) - (pow(b, a));
    cout << "The value of a^b - b^a is: " << ans << endl;




    // Q3
    // Once upon a time Professor Idioticideasinventor was travelling by train. Watching cheerless landscape outside the window, 
    // he decided to invent the theme of his new scientific work. All of a sudden a brilliant idea struck him: to develop an effective
    // algorithm finding an integer number, which is x times less than the sum of all its integer positive predecessors, 
    // where number x is given. As far as he has no computer in the train, you have to solve this difficult problem.
    // Input
    // The first line of the input file contains an integer number x (1 ≤ x ≤ 109).
    // Output
    // Output an integer number — the answer to the problem.
    // Example(s)
    // sample input
    // sample output
    // 1
    // 3
    // sample input
    // sample output
    // 2
    // 5    



    // n = 1/x * (n(n-1)/2)
    // Answer:
    int x;
    cout << "Enter the value of x: ";
    cin >> x;
    double n = 2*x+1;
    cout << "The answer is: " << n << endl;






    // Q4
    // For given integer N (1<=N<=104) find amount of positive numbers not greater than N that coprime with N. Let us call two positive integers 
    // (say, A and B, for example) coprime if (and only if) their greatest common divisor is 1. (i.e. A and B are coprime iff gcd(A,B) = 1).
    // Input
    // Input file contains integer N.
    // Output
    // Write answer in output file.

    // Sample Input
    // 9
    // Sample Output
    // 6    



    // Answer:
    int n;
    cout << "Enter the value of n: ";
    cin >> n;
    int sum = 0;
    
    for(int i = 1; i <= n; i++){
        if (__gcd(i, n) == 1){
            sum += 1;
        }
    }

    cout << "The sum of all integers less than " << n << " that are coprime to " << n << " is: " << sum << endl;







    // Q5
    // There is sequence 1, 12, 123, 1234, ..., 12345678910, ... . Given first N elements of that sequence. 
    // You must determine amount of numbers in it that are divisible by 3.
    // Input
    // Input contains N (1<=N<=231 - 1).
    // Output
    // Write answer to the output.

    // Sample Input
    // 4
    // Sample Output
    // 2    




    // Answer:
    int n;
    cout << "Enter the value of n: ";
    cin >> n;
    string sum = "1";
    int count = 0;

    for (int i = 2; i <= n; i++){
        sum += to_string(i);
        if (stoi(sum) % 3 == 0){
            count++;
        }
    }

    cout << "The concatenated string is: " << sum << endl;
    cout << "The count of numbers divisible by 3 is: " << count << endl;






    
}





// Q6
// You are given a sequence of N integers. Find the number of pairs (i, j)
// such that i < j and A[i] + A[j] is even.
// Input    
// The first line contains an integer N (1 ≤ N ≤ 1000).
// The second line contains N integers A[i] (1 ≤ A[i] ≤ 1000).
// Output
// Output the number of pairs (i, j) such that i < j and A[i] + A[j] is even.
// Sample Input
// 5
// 1 2 3 4 5
// Sample Output

// 6
#include <vector>
#include <algorithm>    
#include <iostream>
using namespace std;
int main() {
    int n;
    cout << "Enter the number of elements in the sequence: ";
    cin >> n;
    
    vector<int> A(n);
    cout << "Enter the elements of the sequence: ";
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    int count = 0;
    
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if ((A[i] + A[j]) % 2 == 0) {
                count++;
            }
        }
    }

    cout << "The number of pairs (i, j) such that A[i] + A[j] is even: " << count << endl;

    return 0;
}




// Q7
// You are given a sequence of N integers. Find the number of pairs (i, j)
// such that i < j and A[i] + A[j] is odd.
// Input
// The first line contains an integer N (1 ≤ N ≤ 1000).
// The second line contains N integers A[i] (1 ≤ A[i] ≤ 1000).
// Output
// Output the number of pairs (i, j) such that i < j and A[i] + A[j] is odd.
// Sample Input
// 5
// 1 2 3 4 5
// Sample Output
// 6
#include <vector>
#include <iostream>
using namespace std;
int main() {
    int n;
    cout << "Enter the number of elements in the sequence: ";
    cin >> n;
    
    vector<int> A(n);
    cout << "Enter the elements of the sequence: ";
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    int count = 0;
    
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if ((A[i] + A[j]) % 2 != 0) {
                count++;
            }
        }
    }

    cout << "The number of pairs (i, j) such that A[i] + A[j] is odd: " << count << endl;

    return 0;
}
