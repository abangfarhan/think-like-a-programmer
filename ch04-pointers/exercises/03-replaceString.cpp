#include <iostream>
#include <string>
typedef char * arrayString;

int length(const arrayString &s) {
    int count = 0;
    while (s[count] != 0)
        count++;
    return count;
}

arrayString substring(arrayString s, int start, int length) {
    arrayString newS = new char[length + 1];
    for (int i=0; i<length; i++) {
        newS[i] = s[start + i];
    }
    newS[length] = 0;
    return newS;
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

void append(arrayString &s, char c) {
    int oldLength = length(s);

    arrayString newS = new char[oldLength+2];
    for (int i = 0; i < oldLength; i++)
        newS[i] = s[i];
    newS[oldLength] = c;
    newS[oldLength+1] = 0;
    delete[] s;
    s = newS;
}

bool stringEqual(const arrayString &s1, const arrayString &s2) {
    int len1 = length(s1);
    if (len1 != length(s2)) return false;
    // alternatively, use while loop
    // but we already have the string length, so...
    for (int i=0; i<len1; i++) {
        if (s1[i] != s2[i]) return false;
    }
    return true;
}

void replaceString(arrayString &source, arrayString target, arrayString replaceText) {
    int sourceLength = length(source);
    int targetLength = length(target);
    int replaceTextLength = length(replaceText);

    arrayString newS = new char[1];
    newS[0] = 0;

    for (int i=0; i<sourceLength; i++) {
        int substringLength = std::min(targetLength, sourceLength-i);
        arrayString sourceSubstring = substring(source, i, substringLength);
        if (stringEqual(sourceSubstring, target)) {
            concatenate(newS, replaceText);
            i += (targetLength-1);
            // substract 1 because the for loop will add 1
        } else {
            append(newS, source[i]);
        }
    }

    delete[] source;
    source = newS;
}

int main() {
    /* implement replaceText function
     * before: "abcdabee"
     * process: replace every occurence of "ab" with "xyz"
     * after: "xyzcdxyzee"
     */
    arrayString a = new char[9];
    a[0] = 'a'; a[1] = 'b'; a[2] = 'c'; a[3] = 'd';
    a[4] = 'a'; a[5] = 'b'; a[6] = 'e'; a[7] = 'e'; a[8] = 0;

    arrayString target = new char[3];
    target[0] = 'a'; target[1] = 'b'; target[2] = 0;

    arrayString replaceText = new char[4];
    replaceText[0] = 'x'; replaceText[1] = 'y'; replaceText[2] = 'z'; replaceText[3] = 0;

    std::cout << a << std::endl;
    replaceString(a, target, replaceText);
    std::cout << a << std::endl;
}
