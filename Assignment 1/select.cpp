#include <iostream>

int main() {
    std::string temp = "";
    int A[30] = {-1000};
    bool complete = false;

    for(int i = 0; complete != true, i < 30; i++) {
        std::cout << "Enter a number (-1000 to stop): ";
        std::cin >> A[i];
    }

    SelectionSort(A);

    std::string display = "";

    for(int i = 0; i < sizeof(A), A[i] != -1000; i++) {
        display = display.append(A[i] + ",");
    }

    std::cout << display;

    return 0;
}

void SelectionSort(int A[]) {
    for(int i = 0; i < sizeof(A), A[i] != -1000; i++) {
        int index = i;

        for(int j = i + 1; j < sizeof(A), A[j] != -1000; j++) {
            if(A[j] < A[i]) {
                index = j;
            }
        }

        if(index != i) {
            int temp = A[i];
            A[i] = A[index];
            A[index] = temp;
        }
    }
}