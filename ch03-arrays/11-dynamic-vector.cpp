#include <iostream>
#include <vector>

int main() {
    std::vector<int> surveyData;
    surveyData.reserve(30); // not strictly necessary
    int surveyResponse;
    std::cout << "Enter next survey response or -1 to end: ";
    std::cin >> surveyResponse;
    
    while (surveyResponse != -1) {
        surveyData.push_back(surveyResponse);
        std::cout << "Enter next survey response or -1 to end: ";
        std::cin >> surveyResponse;
    }

    int vectorSize = surveyData.size();
    const int MAX_RESPONSE = 10;
    int histogram[MAX_RESPONSE];
    for (int i=0; i<MAX_RESPONSE; i++) {
        histogram[i] = 0;
    }
    for (int i=0; i<vectorSize; i++) {
        histogram[surveyData[i]-1]++;
    }
    int mostFrequent = 0;
    for (int i=0; i<MAX_RESPONSE; i++) {
        if (histogram[i] > histogram[mostFrequent])
            mostFrequent = i;
    }
    mostFrequent++;

    std::cout << mostFrequent << std::endl;

    // why storing each number if we only need 1 (the mostFrequent)?
    // we will do it on dynamic-mode.cpp
    return 1;
}
