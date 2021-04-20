#include <iostream>
#include <string>
using namespace std;

string setOfCharacter(int num) {
    switch (num)
    {
    case 2: return "abc";

    case 3: return "def";

    case 4: return "ghi";

    case 5: return "jkl";

    case 6: return "mno";

    case 7: return "pqrs";

    case 8: return "tuv";

    case 9: return "wxyz";
    
    default:
        return "";
    }
}

void keypad(int num, string output) {
    if (num==0) {
        cout << output << endl;
        return;
    }

    int smallNum = num/10;
    string helper = setOfCharacter(num%10);
    int helper_size = helper.size();

    for (int i=0; i<helper_size; i++) {
        keypad(smallNum,output + helper[i]);
    }


    
}

int main() {
    int num;
    cin >> num;
    string output = "";
    keypad(num,output);
    
    return 0;
}