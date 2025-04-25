/*
 * string comparison and sorting
 */
#include <iostream>

// For qsort
#include <cstdlib>

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
        for (int j=0; j < len - 1; j++) {
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

    if (false) {
        string s1 = "Hello";
        string s2 = "Hello world";
        cout << "s2 compared to s1 " << s1.compare(s2) << endl;
        cout << "s1 compared to s2 (negative of above) " << s2.compare(s1) << endl;

        if (s1 > s2) {
            cout << "s1(" << s1 << ") is greater than s2(" << s2 << ")" << endl;
        } else if (s2 > s1) {
            cout << "s2(" << s2 << ") is greater than s1(" << s1 << ")" << endl;
        } else {
            cout << "s1 equals s2 " << s1 << "==" << s2 << endl;
        }
    }

    /*
     * We'll cover 3 algorithms for sorting arrays in place. There are many others,
     * but these are a good place to start and understand how the same problem can
     * be solved in different ways.
     *
     * If you want to research a more complex algorithm not covered, I'd recommend reading
     * about quick sort.
     */
    if (true) {
        const string fruits[] = {
            "apple",
            "grape",
            "blueberry",
            "pear",
            "pear (bartlett)",
            "aaaaaaaaaaaaaaaaaaa"};

        const size_t FRUITS_LEN = sizeof(fruits)/sizeof(fruits[0]);

        //printStringArray(fruits, FRUITS_LEN);
        for (auto f : fruits ) {
            cout << f << endl;
        }


        // bubble sort or stone sort
        if (false) {
            string b[FRUITS_LEN];
            std::copy(fruits, fruits+FRUITS_LEN, b);

            cout << "Bubble Sort" <<endl;
            printStringArray(b, FRUITS_LEN);
            bubbleSort(b, FRUITS_LEN);
            printStringArray(b, FRUITS_LEN);
        }

        // selection sort
        if (false) {
            string b[FRUITS_LEN];
            std::copy(fruits, fruits+FRUITS_LEN, b);

            cout << "Selection Sort" <<endl;
            printStringArray(b, FRUITS_LEN);
            selectionSort(b, FRUITS_LEN);
            printStringArray(b, FRUITS_LEN);
        }

        // insertion sort
        if (false) {
            string b[FRUITS_LEN];
            std::copy(fruits, fruits+FRUITS_LEN, b);
            cout << "Insertion Sort" <<endl;
            printStringArray(b, FRUITS_LEN);
            insertionSort(b, FRUITS_LEN);
            printStringArray(b, FRUITS_LEN);
        }

        // there are other sorting algorithms
    }// end of sorting algorithms

    // Another important aspect is searching data.
    // If the data is known to be sorted there are several approaches to make search
    // We will cover the binary or logarithmic search.
    // This will divide and concur. It will check the midpoint, then know if the search value
    // will be earlier or later in the sequence. Now that it knows which half the value would be in,
    // treat that half as if it were all the data and try the midpoint of that data. Repeat until
    // There are no elements left or until you have found the value.
    if (true) {
        string nato_alpha[] = {
            "alpha",
            "bravo",
            "charlie",
            "delta",
            "echo",
            "foxtrot",
            "golf",
            "hotel",
            "india",
            "juliet",
            "kilo",
            "lima",
            "mike",
            "november",
            "oscar",
            "papa",
            "quebec",
            "romeo",
            "sierra",
            "tango",
            "uniform",
            "victor",
            "whiskey",
            "xray",
            "yankee",
            "zulu",
            };

        string target = "mike";

        bool found = false;
        size_t left = 0;
        size_t cur = -1;
        size_t right = sizeof(nato_alpha)/sizeof(string) - 1;
        while (left <= right && !found) {
            cur = left + (right - left)/2;

            //debug
            cout << "current range : [" << left <<", " << right << "] looking @ " << cur << endl;

            if (nato_alpha[cur] < target) {
                left = cur + 1;
            }  else if (nato_alpha[cur] > target) {
                right = cur - 1;
            } else {
                found = true;
            }
        }
        if (found) {
            cout << "found @ " << cur << endl;
        } else {
            cout << target << " not found!" << endl;
        }

    }

    return 0;
}