#include <iostream>
using namespace std;

int main() {
    string str, reversedStr;
    cout << "Enter a word: ";
    cin >> str;

    reversedStr = string(str.rbegin(), str.rend());

    if (str == reversedStr)
        cout << str << " is a palindrome.\n";
    else
        cout << str << " is not a palindrome.\n";

    return 0;
}
