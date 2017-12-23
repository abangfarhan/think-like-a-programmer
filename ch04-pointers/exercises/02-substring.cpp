#include <iostream>
#include <string>
typedef char * arrayString;

arrayString substring(arrayString s, int start, int length) {
    arrayString newS = new char[length + 1];
    for (int i=0; i<length; i++) {
        newS[i] = s[start + i];
    }
    newS[length] = 0;
    return newS;
}

int main() {
    arrayString a = new char[5];
    a[0] = 't'; a[1] = 'e'; a[2] = 's'; a[3] = 't'; a[4] = 0;
    std::cout << substring(a, 1, 2) << std::endl;
}
