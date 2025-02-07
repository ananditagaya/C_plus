/*(a)
#include <iostream>
#include <string>
using namespace std;
int main() {
    string input;
    cout << "Please enter : ";
    getline(cin, input);
    cout << "You have entered ,  " << input << endl;
    return 0;
}*/

/*(b)
#include <iostream>
#include <string>
using namespace std;

int main() {
    string input;
    cout << "Please enter a string: ";
    getline(cin, input);

    bool isPalindrome = true;
    for (int i = 0; i < input.length() / 2; i++) {
        if (input[i] != input[input.length() - 1 - i]) {
            isPalindrome = false;
            break;
        }
    }

    cout << "\"" << input << "\" is " << (isPalindrome ? "" : "not ") << "a palindrome." << endl;
    return 0;
}*/

/*(c)
#include <iostream>
#include <string>
using namespace std;

int main() {
    string input;
    int frequency[26] = {0}; // (assumed lowercase only)

    cout << "Please enter : ";
    getline(cin, input);
    for (char c : input) {
        if (isalpha(c)) {
            c = tolower(c);
            frequency[c - 'a']++;
        }
    }
    cout << "Character frequency (case insensitive):" << endl;
    for (int i = 0; i < 26; i++) {
        if (frequency[i] > 0) {
            cout << char('a' + i) << ": " << frequency[i] << endl;
        }
    }

    return 0;
}*/
/*(d)
#include <iostream>
#include <string>
using namespace std;

int main() {
    string input;
    cout << "Please enter : ";
    getline(cin, input);
    for (char &c : input) {
        c = tolower(c);
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            c = '%';
        }
    }
    cout << "Modified string: " << input << endl;
    return 0;
}*/





