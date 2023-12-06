#include <iostream>
#include <string>

using namespace std;

bool isVowel(char c) {
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
}

string removeConsecutiveVowels(string str) {
    string result = "";
    int len = str.length();

    for (int i = 0; i < len; i++) {
        // If the current character is a vowel, skip consecutive vowels
        if (!isVowel(str[i])) {
            result.push_back(str[i]);
        } 
        else {
            for (int j = i + 1; j < len; j++) {
                if (isVowel(str[i]) == isVowel(str[j])) {
                    // Skip consecutive vowels
                   i++;
              
                } else {
                    break;
                }
            }
            result.push_back(str[i]);
        }
    }

    return result;
}

int main() {
    string str = "miieesii";
    cout << removeConsecutiveVowels(str) << endl;
    return 0;
}
