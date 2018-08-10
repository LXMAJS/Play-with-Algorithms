#include <iostream>

using namespace std;

void insertionSort(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i; j < 0; j--) {
            if (arr[i] < arr[j - 1])
                swap(arr[i], arr[j - 1]);
            else
                break;
        }
    }
    return;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    int arr[10] = {1,2,2,3,5,2,5,6,7,4};

    selectionSort(arr, 10);

    for(int i = 0; i < 10; i++)
        cout<<arr[i]<<endl;
    return 0;
}