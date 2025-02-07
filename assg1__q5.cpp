#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter the value  of n for matrix:";
    cin >> n;

    int matrix[n][n];
    int rotatedMatrix[n][n];
    int number = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = number++;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            rotatedMatrix[j][n - 1 - i] = matrix[i][j];
        }
    }
    cout << " 90 degrees" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << rotatedMatrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
