#include <iostream>
#include <string>
// #include <vector>
// #include <fstream>
using namespace std;

int doubleValue(int digit){
    int doubled = digit * 2;
    int sum;
    if (doubled > 10)
        sum = 1 + doubled%10;
    else
        sum = doubled;
    return sum;
}

int main(){
    char digit;
    int checksum;
    int checksumEven = 0;
    int checksumOdd = 0;
    int position = 1;
    digit = cin.get();
    while (digit != 10){
        if (position%2 == 0){
            checksumEven += digit - '0';
            checksumOdd += doubleValue(digit-'0');
        } else {
            checksumEven += doubleValue(digit-'0');
            checksumOdd += digit-'0';
        }
        digit = cin.get();
        position++;
    }
    if((position-1)%2 == 0){
        checksum = checksumEven;
    }
    else
        checksum = checksumOdd;

    if(checksum%10 == 0)
        cout << "Valid";
    else
        cout << "Invalid";
}
