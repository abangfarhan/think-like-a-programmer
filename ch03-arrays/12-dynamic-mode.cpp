#include <iostream>

int main() {
    const int MAX_RESPONSE = 10;
    int histogram[MAX_RESPONSE];
    for (int i=0; i<MAX_RESPONSE; i++) {
        histogram[i] = 0;
    }

    int response;
    std::cout << "Enter next response or -1 to end: ";
    std::cin >> response;

    while (response != -1){
        histogram[response-1]++;
        std::cout << "Enter next response or -1 to end: ";
        std::cin >> response;
    }

    for (int i=0; i<MAX_RESPONSE; i++) {
        std::cout << histogram[i];
    }

    int mostFrequent = 0;
    for (int i=1; i<MAX_RESPONSE; i++) {
        if (histogram[i] > histogram[mostFrequent])
            mostFrequent = i;
    }
    mostFrequent++;

    std::cout << mostFrequent << std::endl;

    return 1;
}
