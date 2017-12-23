#include "03-MyString.h"
typedef char * arrayString;

MyString::MyString() {
    str = new char[1];
    str[0] = 0;
}

MyString::MyString(arrayString newStr) {
    str = copiedString(newStr);
    // copy the input
    /*
     *int len = _length(newStr);
     *str = new char[len + 1];
     *int i = 0;
     *while (newStr[i] != 0) {
     *    str[i] = newStr[i];
     *    i++;
     *}
     *str[len] = 0;
     */
}

void MyString::remove(int start, int removedLength) {
    int len = _length(str);
    if (start < 0 || start >= len || start + removedLength > len)
        return;

    int newLen = len - removedLength;
    arrayString newStr = new char[newLen + 1];
    int newIdx = 0;
    for (int i=0; i < len; i++) {
        if (!(i >= start && i < start + removedLength)) {
            newStr[newIdx] = str[i];
            newIdx++;
        }
    }
    newStr[newLen] = 0;
    delete[] str;
    str = newStr;
}

char MyString::operator[](int pos) {
    if (pos < 0 || pos >= _length(str)) return '';
    return str[pos];
}

arrayString MyString::copiedString(const arrayString original) {
    int len = _length(original);
    arrayString newStr = new char[len + 1];
    for (int i=0; i < len; i++)
        newStr[i] = original[i];
    newStr[len] = 0;
    return newStr;
}

MyString& MyString::operator=(const MyString &rhs) {
    if (this != &rhs) {
        delete[] str;
        str = copiedString(rhs.str);
    }
     return *this;
}

MyString::~MyString() {
    delete[] str;
}

char MyString::characterAt(int position) {
    if (pos < 0 || pos >= _length(str)) return '';
    return str[position];
}

int MyString::_length(arrayString str) {
    int len = 0;
    while (str[len] != 0)
        len++;
    return len;
}

void MyString::append(char newChar) {
    int oldLength = _length(str);
    arrayString newS = new char[oldLength + 2];
    for (int i = 0; i < oldLength; i++)
        newS[i] = str[i];
    newS[oldLength] = newChar;
    newS[oldLength + 1] = 0;
    delete[] str;
    str = newS;
}

void MyString::concatenate(arrayString newStr) {
    int len1 = _length(str);
    int len2 = _length(newStr);
    arrayString newS = new char[len1 + len2 + 1];
    int i = 0;

    for (int i=0; i < len1; i++)
        newS[i] = str[i];
    for (int i=0; i < len2; i++)
        newS[len1 + i] = newStr[i];

    newS[len1 + len2] = 0;
    delete[] str;
    str = newS;
}
