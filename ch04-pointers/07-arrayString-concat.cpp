#include <iostream>
typedef char * arrayString;

int length(arrayString s) {
    int count = 0;
    while (s[count] != 0)
        count++;
    return count;
}

void concatenate(arrayString& s1, arrayString s2) {
    int len1 = length(s1);
    int len2 = length(s2);
    int newLen = len1 + len2;

    arrayString newS = new char[newLen + 1];

    for (int i=0; i < len1; i++) {
        newS[i] = s1[i];
    }
    for (int i=0; i < len2; i++) {
        newS[len1 + i] = s2[i];
    }

    newS[newLen] = 0;

    delete[] s1;
    s1 = newS;
}

int main() {
    arrayString str1 = new char[5]; // == char * a = new char[5];
    str1[0] = 't'; str1[1] = 'e'; str1[2] = 's'; str1[3] = 't'; str1[4] = 0;
    arrayString str2 = new char[4];
    str2[0] = 'b'; str2[1] = 'e'; str2[2] = 'd'; str2[3] = 0;

    concatenate(str1, str2);
    std::cout << str1 << std::endl;
    std::cout << str2 << std::endl;

    // test case
    arrayString c = new char[1];
    c[0] = 0;
    concatenate(c, str1);
    std::cout << c << std::endl;
    std::cout << (void*)c << '\n' << (void*)str1 << std::endl;
    // refer to different locations. Good. No cross-linking then.
}
