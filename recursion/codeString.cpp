#include <iostream>
#include <string.h>
using namespace std;

int getInteger(char numeric) {
    int number = numeric - '0';
    return number;
}

char getCharacter(int number) {
    char word = 'a' + number - 1;
    return word;
}

int getCodes(string input, string output[10000]) {
    if (input.size() == 0) {
        output[0] = "";
        return 1;
    }

    if (input.size() == 1) {
        output[1] = getCharacter(getInteger(input[0]));
    }

    string result1[10000], result2[10000];
    int size2 = 0;

    int size1 = getCodes(input.substr(1),result1);
    if(input.size() > 1) {
        if(getInteger(input[0])*10 + getInteger(input[1]) >= 10 && getInteger(input[0])*10 + getInteger(input[1]) <=26) {
            size2 = getCodes(input.substr(2),result2);
        }
    }

    int k=0;
    for (int i=0; i<size1; i++) {
        output[k] = getCharacter(getInteger(input[0])) + result1[i];
        k++;
    }

    for (int i=0; i<size2; i++) {
        output[k] = getCharacter(getInteger(input[0])*10 + getInteger(input[1])) + result2[i];
        k++;
    }

    return k;
}

int main() {
    string input = "1123";
    string output[10000];
    int count = getCodes(input,output);
    for (int i=0; i<count; i++) {
        cout << output[i] << endl;
    }
    cout << endl;
}