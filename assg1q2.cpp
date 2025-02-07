/*(a)
#include <iostream>
using namespace std;

int main() {
    int size;
    cout << "Enter the size of array: ";
    cin >> size;
    int *arr = new int[size];
    cout << "Enter " << size << " integers:" << endl;
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
    cout << "You entered: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    delete[] arr;

    return 0;
}*/

/*(b)
#include <iostream>
using namespace std;

int main() {
    int size;
    cout << "Enter the size of array: ";
    cin >> size;
    int *arr = new int[size];
    cout << "Enter " << size << " integers:" << endl;
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
    cout << "You entered: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "Array in reverse order: ";
    for (int i = size - 1; i >= 0; i--) {
        cout << arr[i] << " ";
    }
    cout << endl;
    delete[] arr;

    return 0;
}*/

/*(c)
#include <iostream>
#include <limits.h>
using namespace std;

int main() {
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    int *arr = new int[size];
    cout << "Enter " << size << " integers:" << endl;
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    int firstMax = INT_MIN, secondMax = INT_MIN;
    int firstMin = INT_MAX, secondMin = INT_MAX;

    for (int i = 0; i < size; i++) {
        if (arr[i] > firstMax) {
            secondMax = firstMax;
            firstMax = arr[i];
        } else if (arr[i] > secondMax && arr[i] != firstMax) {
            secondMax = arr[i];
        }

        if (arr[i] < firstMin) {
            secondMin = firstMin;
            firstMin = arr[i];
        } else if (arr[i] < secondMin && arr[i] != firstMin) {
            secondMin = arr[i];
        }
    }

    cout << "Second largest element: " << secondMax << endl;
    cout << "Second smallest element: " << secondMin << endl;

    delete[] arr;
    return 0;
}

*/
