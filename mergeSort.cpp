#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

void merge(int a[], int l, int m, int r, int *opcount){
    int i, j, k;
    int n1 =  m - l + 1;
    int n2 = r - m;

    int ar1[n1], ar2[n2];

    for(i = 0; i < n1; i++)
        ar1[i] = a[l + i];
    for(j = 0; j < n2; j++)
        ar2[j] = a[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while(i < n1 && j < n2){
        ++*opcount;
        if(ar1[i] <= ar2[j]){
            a[k] = ar1[i];
            i++;
        }
        else{
            a[k] = ar2[j];
            j++;
        }
        k++;
    }

    while(i < n1){
        a[k] = ar1[i];
        i++;
        k++;
    }

    while(j < n2){
        a[k] = ar2[j];
        j++;
        k++;
    }
}

void mergesort(int a[], int l, int r, int *opcount){
    if(l < r){
        //cout << "Inside first function"
        int m = l + (r - l)/2;
        mergesort(a, l, m, opcount);
        mergesort(a, m + 1, r, opcount);
        merge(a, l, m, r, opcount);
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

        mergesort(a, 0, b[t]-1, &count[t]);
        cout << "After quicksort:\n";
        for(int i = 0; i < b[t]; i++)
            cout << a[i] << " ";
        cout << endl;
    }

    cout << "n\topcount\n";
    for(int i = 0; i < 4; i++){
        cout << b[i] << "\t" << count[i] << endl;
    }

    // for(int i = 0; i < n; i++)
    //     cin >> a[i];
    //int opcount = 0;
    // mergesort(a, 0, n - 1), &opcount);
    // for(int i = 0; i < n; i++)
    //     cout << a[i] << " ";
    // cout << endl;
    //cout << opcount;

    return 0;
}
