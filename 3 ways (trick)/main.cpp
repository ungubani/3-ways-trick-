// C++ program for 3-way quick sort
#include <iostream>
// #include <bits/stdc++.h>
using namespace std;

int step_number = 0;



// A utility function to print an array
void printarr(char* a, int n)
{
    for (int i = 0; i < n; ++i)
        printf("%c  ", a[i]);
    printf("\n");
}


/* This function partitions a[] in three parts
   a) a[l..i] contains all elements smaller than pivot
   b) a[i+1..j-1] contains all occurrences of pivot
   c) a[j..r] contains all elements greater than pivot */

void partition(char a[], int l, int r, int& i, int& j, int size)  // size using for printing array
{
    
    i = l - 1, j = r;
    int p = l - 1, q = r;
    int v = a[r];

    cout << "\n*New partition*" << endl;
    printf("i= %d, j= %d, p= %d, q= %d, v= '%c'\n", i, j, p, q, v);

    while (true) {
        // From left, find the first element greater than
        // or equal to v. This loop will definitely
        // terminate as v is last element
        while (a[++i] < v)
            ;

        // From right, find the first element smaller than
        // or equal to v
        while (v < a[--j])
            if (j == l)
                break;

        // If i and j cross, then we are done
        if (i >= j)
            break;

        // Swap, so that smaller goes on left greater goes
        // on right
        swap(a[i], a[j]);

        printf("Smaller goes on left %d && %d. Array after step %d: ", i, j, step_number++);
        printarr(a, size);


        // Move all same left occurrence of pivot to
        // beginning of array and keep count using p
        if (a[i] == v) {
            p++;
            swap(a[p], a[i]);

            printf("Swapped %d && %d. Array after step %d: ", p, i, step_number++);
            printarr(a, size);
        }

        // Move all same right occurrence of pivot to end of
        // array and keep count using q
        if (a[j] == v) {
            q--;
            swap(a[j], a[q]);

            printf("Swapped %d && %d. Array after step %d: ", j, q, step_number++);
            printarr(a, size);
        }
    }

    // Move pivot element to its correct index
    swap(a[i], a[r]);

    printf("pivot to correct index %d && %d. Array after step %d: ", i, r, step_number++);
    printarr(a, size);


    // Move all left same occurrences from beginning
    // to adjacent to arr[i]
    j = i - 1;
    for (int k = l; k <= p; k++, j--) {
        swap(a[k], a[j]);

        printf("k=%d && j=%d. Array after step %d: ",k, j, step_number++);
        printarr(a, size);
    }


    // Move all right same occurrences from end
    // to adjacent to arr[i]
    i = i + 1;
    for (int k = r - 1; k >= q; k--, i++) {
        swap(a[i], a[k]);

        printf("i= %d && k= %d. Array after step %d: ", i, k, step_number++);
        printarr(a, size);
    }
}

// 3-way partition based quick sort
void quicksort(char a[], int l, int r, int size)
{
    if (r <= l)
        return;

    int i, j;

    // Note that i and j are passed as reference
    partition(a, l, r, i, j, size);

    // Recur
    quicksort(a, i, r, size);
    quicksort(a, l, j, size);
    
    
    
}

// Driver code
int main()
{
    cout << "***QS WITH DUTCH_FLAG_PARTITION***\n" << endl;

    int size;

    cout << "Input length char array: " << endl;

    cin >> size;
    char* a = new char[size];

    cout << "Input char's array (new element with space): " << endl;

    for (int i = 0; i < size; i++) {
        cin >> a[i];
    }
    cout << "\n___Array is writen___\n\n" << endl;

    // Function Call
    cout << "Input array: "; printarr(a, size);
    quicksort(a, 0, size - 1, size);
    cout << "\n********************************************\nOutput array: "; 
    printarr(a, size);

    delete[] a;

    system("pause");
    return 0;
}