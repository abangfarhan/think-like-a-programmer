#include <iostream>
#include <string>
typedef char * arrayString;

/* Demonstrate the Usage of typedef.
 * arrayString is a pointer to a char in the heap.
 * Note that a pointer which refers to a block of objects
 * can be accessed using array notation!
 */

char charAt(arrayString s, int position) {
    return s[position];
}

int main() {
    // allocate 5 memory location of type char
    arrayString a = new char[5];
    // actually, it's equivalent to:
    // arrayString *a = new char[5];
    // if we have not set typedef char * arrayString
    // but now we have to use the asterisk

    a[0] = 't'; a[1] = 'e'; a[2] = 's'; a[3] = 't';
    a[4] = 0; // EOL character
    std::cout << a << std::endl;
    std::cout << a[0] << std::endl;
    std::cout << charAt(a, 1) << std::endl;

    /* Our method of assigning 0 to the last char
     * is the same method used by std::string
     */
    std::string s1 = "Hello";
    std::cout << (s1[4] == 0) << std::endl; // true
}
