#include <iostream>

using namespace std;

int main(){
    int rowMax = 4;
    int colMax = 8;
    int pad = 0;
    for(int row=0; row < rowMax; row++){
        for(int col=0; col < colMax; col++){
            if(col >= pad && col < (colMax - pad)){
                cout << '#';
            } else {
                cout << ' ';
            }
        }
        pad++;
        cout << endl;
    }

    cout << endl;

    rowMax = 8;
    colMax = 8;
    pad = 3;
    int temp = -1;
    for(int row=0; row < rowMax; row++){
        for(int col=0; col < colMax; col++){
            if(col >= abs(pad) && col < (colMax - abs(pad))){
                cout << '#';
            } else {
                cout << ' ';
            }
        }
        pad--;
        if(pad == temp){
            pad = 0;
            temp = 0;
        }
        cout << endl;
    }

    cout << endl;

    rowMax = 8;
    colMax = 14;
    pad = 0;
    int mid = 1;
    for(int row=0; row < rowMax; row++){
        for(int col=0; col < colMax; col++){
            if(col >= pad && col < (colMax - pad) && 
                (col < mid || col >= (colMax - mid))){
                cout << '#';
            } else {
                cout << ' ';
            }
        }
        mid = mid + 2;
        cout << endl;
    }
    return 1;
}
