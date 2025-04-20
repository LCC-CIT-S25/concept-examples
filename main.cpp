/*
 * string comparison and sorting
 */
#include <iostream>

using namespace std;

void printStringArray(const string strs[], size_t len) {
    for (size_t i=0; i<len; i++) {
        cout << "["<< i <<"] " << strs[i] << endl;
    }
}

/*
 * Bubble sort
 * Each iteration it moves adjacent elements in the right direction
 * Once it completes over the array with no changes, it is done
 */
void bubbleSort(string arr[], size_t len) {

    for (size_t i = 0, swaps=1; (i<len && swaps > 0); i++) {
        swaps = 0;
        for (int j=0; j < len-1; j++) {
            if (arr[j] > arr[j+1]) {
                string tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
                swaps++;
            }
        }
    }
}

/*
 *Selection Sort
 *
 * Each iteration it moves the i^th smallest to the i^th position.
 * It considers the elements from i to the end and moves the smallest of them to the i position.
 */
void selectionSort(string arr[], size_t len) {
    for (size_t i=0; i<len; i++) {
        size_t min_idx = i;
        for (size_t j=i; j<len; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        string tmp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = tmp;
    }
}

/*
 * Insertion sort
 *
 * Each iteration it makes sure the first i elements are in order.
 * It takes the i+1 and inserts it in the correct position.
 */
void insertionSort(string arr[], size_t len) {
    for (size_t i=1; i<len; i++) {
        string tmp = arr[i];
        for (int j=i-1; j>=0; j--) {
            if (arr[j] > tmp) {
                arr[j+1] = arr[j];
                arr[j] = tmp;
            }
        }
    }
}

int main() {
    if (1) {
        string s1 = "hello";
        string s2 = "hello world";
        cout << "s2 compared to s1 " << s1.compare(s2) << endl;
        cout << "s1 compared to s2 (negative of above) " << s2.compare(s1) << endl;
    }

    if (1) {
        const string fruits[] = {"apple", "grape", "blueberry", "pear", "pear (bartlett)"};
        //printStringArray(fruits);
        for (auto f : fruits ) {
            cout << f << endl;
        }

        const size_t len = sizeof(fruits)/sizeof(fruits[0]);
        // bubble sort or stone sort
        {
            string b[len];
            std::copy(fruits, fruits+len, b);
            cout << "Bubble Sort" <<endl;
            printStringArray(b, len);
            bubbleSort(b, len);
            printStringArray(b, len);
        }

        // selection sort
        {
            string b[len];
            std::copy(fruits, fruits+len, b);
            cout << "Selection Sort" <<endl;
            printStringArray(b, len);
            selectionSort(b, len);
            printStringArray(b, len);
        }

        // insertion sort
        {
            string b[len];
            std::copy(fruits, fruits+len, b);
            cout << "Insertion Sort" <<endl;
            printStringArray(b, len);
            insertionSort(b, len);
            printStringArray(b, len);
        }

        // quick sort (not covered here)

    }

    return 0;
}