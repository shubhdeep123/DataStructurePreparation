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

int keypad(int num, string output[]) {
    if (num==0) {
        return 1;
    }

    int smallNum = num/10;
    string helper = setOfCharacter(num%10);
    int helper_size = helper.size();
    int smallOutputSize = keypad(smallNum, output);

    for(int i=0; i<helper_size-1; i++) {
        for(int j=0; j<smallOutputSize; j++) {
            output[j+(i+1)*smallOutputSize] = output[j];
        }
    }

    int k=0;
    for (int i=0; i<helper_size; i++) {
        for (int j=0; j<smallOutputSize; j++) {
            output[k] = output[k] + helper[i];
            k++;
        }
    }

    return helper_size * smallOutputSize;
}

int main() {
    string output[1000];
    int count = keypad(234,output);

    for (int i=0; i<count; i++) {
        cout << output[i] << endl;
    }
    return 0;
}