# include <iostream>

using namespace std;

int findPos(int array[], int low, int high) {
    int val = array[low];
    while (low < high) {
        while (low < high && array[high] >= val)
            --high;
        array[low] = array[high];

        while (low < high && array[low] <= val)
            ++low;
        array[high] = array[low];
    }
    array[low] = val;
    return low;
}

void quickSort(int array[], int low, int high) {
    int pos;
    if (low < high) {
        pos = findPos(array, low, high);
        quickSort(array, low, pos - 1);
        quickSort(array, pos + 1, high);
    }
}

int getMinDiff(int *a, int n) {
    quickSort(a, 0, n - 1);
    int min = a[1] - a[0], diff = 0;
    for (int i = 0; i < n - 1; ++i) {
        diff = a[i + 1] - a[i];
        if (diff < min)
            min = diff;
    }
    return min;
}

int main() {
    int test[] = {1, 2, 34, 55, 33, 24, 12, 4};
    quickSort(test, 0, 8);
    for (int i : test) {
        cout << i << " ";
    }
    int min_diff = getMinDiff(test, 8);
    cout << endl << "最接近的两个数只差是: " << min_diff << endl;
    return 0;
}