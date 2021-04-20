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

void printCode(string input, string output) {
    if (input.size() == 0) {
        cout << output << endl;
        return;
    }

    int number1 = getInteger(input[0]);
    char word1 = getCharacter(number1);
    printCode(input.substr(1),output + word1);

    int number2 = getInteger(input[0])*10 + getInteger(input[1]);
    char word2 = getCharacter(number2);
    if (number2 >= 10 && number2 <=26) {
        printCode(input.substr(2),output + word2);
    }
}

void printAllPossibleCodes(string input) {
    /*
    Given the input as a string, print all its possible combinations. You do not need to return anything.
    */
   string output = "";
   printCode (input,output);
}

int main () {
    printAllPossibleCodes("1123");
    return 0;
}