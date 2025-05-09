#include <iostream>
#include <vector>

void countingSort(std::vector<int>& arr) {
    // Find the maximum element in the array
    int max = arr[0];
    int min = arr[0];
    for (int num : arr) {
        if (num > max) {
            max = num;
        }
        if (num < min) {
            min = num;
        }
    }

    // Create a count array to store the count of each element
    int range = max - min + 1;
    std::vector<int> count(range, 0);

    // Count the occurrences of each element in the input array
    for (int num : arr) {
        count[num - min]++;
    }

    // Reconstruct the sorted array from the count array
    int index = 0;
    for (int i = 0; i < range; i++) {
        while (count[i] > 0) {
            arr[index] = i + min;
            index++;
            count[i]--;
        }
    }
}

int main() {
    std::vector<int> arr = {4, 2, 2, 8, 3, 3, 1};
    
    std::cout << "Original Array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    countingSort(arr);

    std::cout << "Sorted Array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}