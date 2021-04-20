#include <iostream>
#include <string>
using namespace std;

void duplicateCharacter (string input) {
    for (int i=0; i<input.size(); i++) {
        for (int j=i; j<input.size(); j++) {
            if(input[i] = input[j]) {
                cout << input[i] << endl;
            }
        }
    }
}

int main() {
    duplicateCharacter("abcabc");
}