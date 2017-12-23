#include <iostream>
typedef char * arrayString;

char charAt(arrayString s, int position) {
    return s[position];
}

int length(arrayString s) {
    int count = 0;
    while (s[count] != 0)
        count++;
    return count;
}

void append(arrayString &s, char c) {
    /* try to use arrayString s instead of arrayString &s
     * you will find that the function will make the passed in
     * arrayString disappear
     * This is my hypotheses:
     * - if we just use arrayString s, the function
     *   will make a copy of the pointer
     * - if we use arrayString &s, the function
     *   will actually use the pointer variable
     * - probably wrong: why would it disappear, then?
     * - the reason it disappears is because we delete[] s
     */

    int oldLength = length(s);

    // newS is a local pointer, but the pointee is globally accessible
    arrayString newS = new char[oldLength+2];
    for (int i = 0; i < oldLength; i++)
        newS[i] = s[i];
    newS[oldLength] = c;
    newS[oldLength+1] = 0;
    // deallocate the pointee of s
    // then make s refer to newS's pointee
    delete[] s;
    std::cout<< "newS address: " << (void*)newS << std::endl;
    s = newS;
}

int main() {
    arrayString a = new char[8]; // == char * a = new char[5];
    a[0] = 't'; a[1] = 'e'; a[2] = 's'; a[3] = 't';
    a[4] = 'i'; a[5] = 'n'; a[6] = 'g'; a[7] = 0;
    std::cout << "a original: " << a << std::endl;
    std::cout << "a original pointing to: " << (void*)a << std::endl;
    std::cout << "a original self address: " << &a << std::endl;
    append(a, '!');
    std::cout << "a new: " << a << std::endl;
    std::cout << "a new pointing to: " <<(void*)a << std::endl;
    std::cout << "a new self address: " << &a << std::endl;

    /* old comment:
     * how could they refer to the same memory???
     * because &a will refer to the location of the pointer
     * i.e. the location of a itself, not the thing pointed by a
     * refer to https://stackoverflow.com/questions/5270277/character-pointers-in-c
     */

    /* char pointer is treated differently by cout than int pointers
     * suppose you have an int pointer named X
     * and you say cout << X, what'll be printed is an address
     * But if you have a char pointer named Y
     * and you say cout << Y, you will get the char[s] printed
     * If Y refer to 1 char only, the cout will print
     * the content of THREE memory locations
     */

}
