#include <iostream>
using namespace std;


void printStars(int stars) {
    if (stars == 0) {
        return; 
    }
    cout << "*";
    printStars(stars - 1); 
}

void printPyramid(int rows, int currentRow = 1) {
    if (currentRow > rows) {
        return; 
    }
    printStars(currentRow);

    cout << endl; 

    printPyramid(rows, currentRow + 1); 
}

int main() {
    int n;

    cout << "Enter pyramid row number: ";
    cin >> n;

    printPyramid(n);

    return 0;
}
