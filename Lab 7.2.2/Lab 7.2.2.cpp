#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

void Create(int** a, const int k, const int n, const int Low, const int High, int i, int j) {
    if (i >= k) {
        return;
    }

    if (j >= n) {
        Create(a, k, n, Low, High, i + 1, 0);
        return;
    }

    a[i][j] = Low + rand() % (High - Low + 1);
    Create(a, k, n, Low, High, i, j + 1);
}

void Print(int** a, const int k, const int n, int i, int j) {
    if (i >= k) {
        return;
    }

    if (j >= n) {
        cout << endl;
        Print(a, k, n, i + 1, 0);
        return;
    }

    cout << setw(4) << a[i][j];
    Print(a, k, n, i, j + 1);
}

int FindLargestOfMinimums(int** a, const int k, const int n, int i) {
    if (i >= k) {
        return -1;
    }

    int minInRow = a[i][0];
    for (int j = 1; j < n; j++) {
        minInRow = min(minInRow, a[i][j]);
    }

    int largestMinInRest = FindLargestOfMinimums(a, k, n, i + 1);

    return (largestMinInRest == -1) ? minInRow : max(minInRow, largestMinInRest);
}

int main() {
    srand((unsigned)time(NULL));
    int Low = 7;
    int High = 65;
    int k, n;

    cout << "k = "; cin >> k;
    cout << "n = "; cin >> n;

    int** a = new int* [k];
    for (int i = 0; i < k; i++)
        a[i] = new int[n];

    Create(a, k, n, Low, High, 0, 0);
    Print(a, k, n, 0, 0);

    int result = FindLargestOfMinimums(a, k, n, 0);

    if (result != -1)
        cout << "The largest of the minimum elements in each row: " << result << endl;
    else
        cout << "Matrix is empty." << endl;

    for (int i = 0; i < k; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}
