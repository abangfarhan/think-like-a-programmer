#include <iostream>

int main() {
    /* example of a memory leak.
     * a memory is allocated in the heap, but then
     * the pointer to that memory is 'removed'
     */
    int *intPtr = new int;
    // intPtr = NULL;
    // now we should do this instead
    intPtr = nullptr;
    // although both are actually the same:
    std::cout << (NULL == nullptr) << std::endl; // 1
}
