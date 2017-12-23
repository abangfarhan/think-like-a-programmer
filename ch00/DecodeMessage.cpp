#include <iostream>

using namespace std;

char punctuation (int num){
    char result;
    switch(num){
        case 1:
            result = '!';
            break;
        case 2:
            result = '?';
            break;
        case 3:
            result = ',';
            break;
        case 4:
            result = '.';
            break;
        case 5:
            result = ' ';
            break;
        case 6:
            result = ';';
            break;
        case 7:
            result = '"';
            break;
        case 8:
            result = '\'';
            break;
    }
    return result;
}

bool isChangeMode (int num, int mode){    
    if (mode==0 || mode==1) {
        if(num%27 == 0)
            return true;
    } else {
        if(num%9 == 0){
            return true;
        }
    }
    return false;
}

char decode (int num, int mode);

int main() {
    cout << "Enter code: ";
    char digitChar;
    char letter;
    int digitInt;
    int mode = 0;
    while (true){
        digitChar = cin.get();
        digitInt = 0;
        while (true) {
            digitInt = digitInt*10 + (digitChar - '0');
            digitChar = cin.get();
            if (digitChar == ',' or digitChar == 10) break;
        }

        if (isChangeMode(digitInt, mode)) {
            mode = (mode + 1) % 3;
            continue;
        }
        letter = decode(digitInt, mode);
        cout << letter;

        if (digitChar == 10) break;
    }
    return 1;
}

char decode (int num, int mode) {
    char decoded;
    if (mode == 0)
        decoded = num%27 + 'A' - 1;
    else if (mode == 1)
        decoded = num%27 + 'a' - 1;
    else
        decoded = punctuation(num%9);
    return decoded;
}
