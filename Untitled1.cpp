#include <iostream>
#include <string>
using namespace std;

// Forward declarations
int q0(char);
int q1(char);
int q2(char);
int q3(char);

// q0 → starting state
int q0(char c) {
    if (c == '1') return 1;  // go to q1
    else return 0;           // stay in q0
}

// q1
int q1(char c) {
    if (c == '1') return 2;  // go to q2
    else return 0;           // go back to q0
}

// q2
int q2(char c) {
    if (c == '1') return 3;  // go to q3 (accepting)
    else return 0;           // go back to q0
}

// q3 → accepting state
int q3(char c) {
    return 3;  // stay in q3 no matter 0 or 1
}

int main() {
    string input;
    cout << "Enter a binary string: ";
    cin >> input;

    int state = 0;  // start at q0

    for (char c : input) {
        switch (state) {
            case 0: state = q0(c); break;
            case 1: state = q1(c); break;
            case 2: state = q2(c); break;
            case 3: state = q3(c); break;
        }
    }

    if (state == 3)
        cout << "✅ Accepted (contains 111)" << endl;
    else
        cout << "❌ Rejected (does not contain 111)" << endl;

    return 0;
}
