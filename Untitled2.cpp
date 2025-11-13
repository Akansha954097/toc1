#include <iostream>
#include <string>
using namespace std;

// Function declarations
int q0(char);
int q1(char);
int q2(char);
int q3(char);
int q4(char);

// q0 → start
int q0(char c) {
    if (c == '1') return 1;
    else return 0;
}

// q1
int q1(char c) {
    if (c == '1') return 2;
    else return 1;
}

// q2  (2 ones seen)
int q2(char c) {
    if (c == '1') return 3;
    else return 2;
}

// q3  (3 ones seen)
int q3(char c) {
    if (c == '1') return 4;  // more than 3 ones
    else return 3;
}

// q4 → trap state
int q4(char c) {
    return 4; // stay in trap
}

int main() {
    string input;
    cout << "Enter a binary string: ";
    cin >> input;

    int state = 0; // start at q0

    for (char c : input) {
        switch (state) {
            case 0: state = q0(c); break;
            case 1: state = q1(c); break;
            case 2: state = q2(c); break;
            case 3: state = q3(c); break;
            case 4: state = q4(c); break;
        }
    }

    if (state == 2 || state == 3)
        cout << "✅ Accepted (exactly 2 or 3 ones)\n";
    else
        cout << "❌ Rejected (not exactly 2 or 3 ones)\n";

    return 0;
}
