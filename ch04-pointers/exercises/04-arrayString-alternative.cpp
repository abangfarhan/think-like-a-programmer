#include <iostream>
typedef char * arrayString;

void printString(arrayString s) {
    for(int i=1; i<=s[0]; i++) {
        std::cout << s[i];
    }
    std::cout << endl;
}

int main() {
    arrayString s = new char[5];
    s[0] = 4;
    s[1] = 't'; s[2] = 'e'; s[3] = 's'; s[4] = 't';
    printString(s);
}
