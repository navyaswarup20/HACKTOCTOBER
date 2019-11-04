#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int a[], int p, int r, int *opcount){
    int x = a[r];
    int i = p - 1;
    for (int j = p; j <= r - 1; j++) {
        ++*opcount;
        if(a[j] <= x){
            i += 1;
            swap(&a[i], &a[j]);
        }
    }
    swap(&a[i + 1], &a[r]);
    return (i + 1);
}

void quicksort(int a[], int p, int r, int *opcount){
    if(p <= r){
        int q = partition(a, p, r, opcount);
        quicksort(a, p, q - 1, opcount);
        quicksort(a, q + 1, r, opcount);
    }
}

int main() {
    // cout << "Size:\n";
    // int n;
    // cin >> n;
    // int a[n];
    int b[] = {5, 10, 15, 20};
    int count[4] = {0};
    //cout << "\nEnter array:\n";
    for(int t = 0; t < 4; t++){
        int a[b[t]];
        for(int i = 0; i < b[t]; i++)
            cin >> a[i];

        quicksort(a, 0, b[t]-1, &count[t]);
        cout << "After quicksort:\n";
        for(int i = 0; i < b[t]; i++)
            cout << a[i] << " ";
        cout << endl;
    }

    cout << "n\topcount\n";
    for(int i = 0; i < 4; i++){
        cout << b[i] << "\t" << count[i] << endl;
    }
    return 0;
}
