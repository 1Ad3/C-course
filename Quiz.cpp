#include <iostream>
using namespace std;

int main() {
    int score = 0, answer;

    cout << "Quiz Game\n";

    cout << "1. What is the capital of France?\n";
    cout << "1. Berlin  2. Paris  3. Madrid  4. Rome\n";
    cout << "Your answer: ";
    cin >> answer;
    if (answer == 2) score++;

    cout << "2. Who wrote 'Hamlet'?\n";
    cout << "1. Dickens  2. Shakespeare  3. Austen  4. Twain\n";
    cout << "Your answer: ";
    cin >> answer;
    if (answer == 2) score++;

    cout << "3. What is the largest planet?\n";
    cout << "1. Earth  2. Venus  3. Jupiter  4. Mars\n";
    cout << "Your answer: ";
    cin >> answer;
    if (answer == 3) score++;

    cout << "You scored " << score << " out of 3.\n";

    return 0;
}
