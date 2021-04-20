#include <iostream>
using namespace std;

#include<string.h>
bool checkAB(char input[]) {
	int n = strlen(input);
    if(input[0] == '\0') {
        return true;
    }
    
    if (input[0] != 'a') {
        return false;
    } else {
        if(input[0] == 'a' && (input[1] == '\0' || input[1] == 'a')) {
        	return checkAB(input+1);
        } else if (input[0] == 'a' && (input[1]=='b' && input[2]=='b')) {
            return checkAB(input+3);
        } else {
            return false;
        }
    }

}

int main () {
    char input[] = "abababa";
    cout << checkAB(input) << endl;
}