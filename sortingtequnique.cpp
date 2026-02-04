#include <iostream>
using namespace std;


void display(int a[], int n) {
    for(int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}


void bubbleSort(int a[], int n) {
    for(int i = 0; i < n-1; i++)
        for(int j = 0; j < n-i-1; j++)
            if(a[j] > a[j+1])
                swap(a[j], a[j+1]);
}

void selectionSort(int a[], int n) {
    for(int i = 0; i < n-1; i++) {
        int min = i;
        for(int j = i+1; j < n; j++)
            if(a[j] < a[min])
                min = j;
        swap(a[min], a[i]);
    }
}

void insertionSort(int a[], int n) {
    for(int i = 1; i < n; i++) {
        int key = a[i];
        int j = i - 1;
        while(j >= 0 && a[j] > key) {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
    }
}
void merge(int a[], int l, int m, int r) {
    int temp[100];
    int i=l, j=m+1, k=0;

    while(i<=m && j<=r) {
        if(a[i] < a[j]) temp[k++] = a[i++];
        else temp[k++] = a[j++];
    }

    while(i<=m) temp[k++] = a[i++];
    while(j<=r) temp[k++] = a[j++];

    for(i=l, k=0; i<=r; i++, k++)
        a[i] = temp[k];
}

void mergeSort(int a[], int l, int r) {
    if(l < r) {
        int m = (l + r) / 2;
        mergeSort(a, l, m);
        mergeSort(a, m+1, r);
        merge(a, l, m, r);
    }
}

int partition(int a[], int low, int high) {
    int pivot = a[high];
    int i = low - 1;

    for(int j = low; j < high; j++) {
        if(a[j] < pivot) {
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i+1], a[high]);
    return i+1;
}

void quickSort(int a[], int low, int high) {
    if(low < high) {
        int pi = partition(a, low, high);
        quickSort(a, low, pi-1);
        quickSort(a, pi+1, high);
    }
}

int main() {
    int n, choice;
    int a[100];

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements:\n";
    for(int i = 0; i < n; i++)
        cin >> a[i];

    cout << "\nChoose Sorting Technique\n";
    cout << "1. Bubble Sort\n";
    cout << "2. Selection Sort\n";
    cout << "3. Insertion Sort\n";
    cout << "4. Merge Sort\n";
    cout << "5. Quick Sort\n";
    cout << "Enter choice: ";
    cin >> choice;

    switch(choice) {
        case 1: bubbleSort(a, n); break;
        case 2: selectionSort(a, n); break;
        case 3: insertionSort(a, n); break;
        case 4: mergeSort(a, 0, n-1); break;
        case 5: quickSort(a, 0, n-1); break;
        default: cout << "Invalid choice"; return 0;
    }

    cout << "\nSorted Array:\n";
    display(a, n);

    return 0;
}
