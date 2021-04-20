#include <iostream>
#include <string.h>
using namespace std;

void print_Subs (string input, string output) {
    if (input.length() == 0) {
        cout << output << endl;
        return;
    }

    print_Subs(input.substr(1),output);
    print_Subs(input.substr(1),output + input[0]);
}

int main() {
    string input;
    getline(cin,input);
    string output = "";
    print_Subs(input,output);
    return 0;

}