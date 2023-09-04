#include <iostream>
using namespace std;

void SelectionSort(int A[], int);

int A[30]; 

int main() {
    int value;
    int length = 0;
    bool complete = false;

    for(int i = 0; complete != true && i < 30; i++) {
        cout << "Enter a number (-1000 to stop): ";
        cin >> value;
	A[i] = value;

	if(A[i] == -1000) {
	    complete = true;
	}

	length++;
    }

    SelectionSort(A, length - 1);

    return 0;
}

void SelectionSort(int A[], int length) {
    cout << "Current Array: ";
    for(int i = 0; i < length; i++) {
	cout << A[i] << ",";
    }
    cout << endl;
    
    for(int i = 0; i < length; i++) {
        for(int j = i + 1; j < length; j++) {
            if(A[j] < A[i]) {
                int temp = A[i];
		A[i] = A[j];
		A[j] = temp;
            }
        }
    }

    cout << "Sorted Array: ";

    for(int i = 0; i < length; i++) {
        cout << A[i] << ",";
    }

    cout << endl;
}
