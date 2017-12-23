#include <iostream>
#include <vector>
#include <string>

int main(){
    const char charSubstitute[26] = {
        'P','Q','R','S','T','U','V','W','X','Y','Z','A','B',
        'C','D','E','F','G','H','I','J','K','L','M','N','O'
    };

    std::vector<char> originalMessage;
    originalMessage.reserve(30);
    std::cout << "Insert your message in CAPS LOCK: ";
    char charInput = std::cin.get();
    while (charInput != 10) {
        originalMessage.push_back(charInput);
        charInput = std::cin.get();
    }

    int messageSize = originalMessage.size();
    char encodedMessage[messageSize];
    for (int i=0; i<messageSize; i++) {
        char encodedChar;
        if (originalMessage[i] < 'A' || originalMessage[i] > 'Z') {
            encodedChar = originalMessage[i];
        } else {
            encodedChar = charSubstitute[originalMessage[i] - 'A'];
        }
        encodedMessage[i] = encodedChar;
    }

    char decodedMessage[messageSize];
    for (int i=0; i<messageSize; i++) {
        char decodedChar;
        if (encodedMessage[i] < 'A' || encodedMessage[i] > 'Z') {
            decodedChar = encodedMessage[i];
        } else {
            for (int j=0; j<26; j++) {
                if (encodedMessage[i] == charSubstitute[j]) {
                    decodedChar = 'A' + j;
                    break;
                }
            }
        }
        decodedMessage[i] = decodedChar;
    }

    std::cout << "Encoded Message: ";
    for (char c: encodedMessage)
        std::cout << c;

    std::cout << "\nDecoded Message: ";
    for (char c: decodedMessage)
        std::cout << c;
    std::cout << std::endl;
    
    // ROT-N Algorithm
    // int shift = 13;
    // char charInput = 'A';
    // char a = ((charInput - 'A') + shift)%26 + 'A';
    // std::cout << a << std::endl;
}
