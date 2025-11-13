#include <iostream>
#include <string>
using namespace std;

// Function declarations (each represents a state)
int q0(string s);
int qAA(string s);
int qAB(string s);
int qBA(string s);
int qBB(string s);

// Helper function to check if first two == last two
bool isAccepted(string s) {
    if (s.length() < 4) return false;
    string first2 = s.substr(0, 2);
    string last2 = s.substr(s.length() - 2, 2);
    return (first2 == last2);
}

// q0 = Start state
int q0(string s) {
    if (s.length() < 2) {
        cout << "❌ Rejected (string too short)\n";
        return 0;
    }

    string first2 = s.substr(0, 2);

    if (first2 == "aa") return qAA(s);
    else if (first2 == "ab") return qAB(s);
    else if (first2 == "ba") return qBA(s);
    else if (first2 == "bb") return qBB(s);
    else {
        cout << "❌ Invalid input\n";
        return 0;
    }
}

// State when first two are "aa"
int qAA(string s) {
    cout << "Current state: qAA (first two = aa)\n";
    if (isAccepted(s))
        cout << "✅ Accepted (first two and last two are same: 'aa')\n";
    else
        cout << "❌ Rejected (first two != last two)\n";
    return 0;
}

// State when first two are "ab"
int qAB(string s) {
    cout << "Current state: qAB (first two = ab)\n";
    if (isAccepted(s))
        cout << "✅ Accepted (first two and last two are same: 'ab')\n";
    else
        cout << "❌ Rejected (first two != last two)\n";
    return 0;
}

// State when first two are "ba"
int qBA(string s) {
    cout << "Current state: qBA (first two = ba)\n";
    if (isAccepted(s))
        cout << "✅ Accepted (first two and last two are same: 'ba')\n";
    else
        cout << "❌ Rejected (first two != last two)\n";
    return 0;
}

// State when first two are "bb"
int qBB(string s) {
    cout << "Current state: qBB (first two = bb)\n";
    if (isAccepted(s))
        cout << "✅ Accepted (first two and last two are same: 'bb')\n";
    else
        cout << "❌ Rejected (first two != last two)\n";
    return 0;
}

int main() {
    string input;
    cout << "Enter a string over {a, b}: ";
    cin >> input;

    q0(input); // Start FA

    return 0;
}
