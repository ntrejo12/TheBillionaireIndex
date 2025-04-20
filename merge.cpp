#include "billionaire.h"
#include <string>
#include <vector>
#include <iostream>
using namespace std;

//code from geeksforgeeks
//https://www.geeksforgeeks.org/merge-sort/

void merge(vector<Billionaire>& data, int left, int mid, int right) {

    int n1 = mid - left + 1;
    int n2 = right - mid;
    vector<Billionaire> L(n1), R(n2);

    for (int i = 0; i < n1; i++) {
        L[i] = data[i + left];
    }
    for (int i = 0; i < n2; i++) {
        R[i] = data[i + mid + 1];
    }
    int i = 0, j = 0;
    int k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            data[k] = L[i];
            i++;
        }
        else {
            data[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        data[k] = L[i];
        i++;
        j++;
    }
    while (j < n2) {
        data[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<Billionaire>& data, int left, int right) {
    if (left >= right) {
        return;
    }
    int mid = left + (right - left) / 2;
    mergeSort(data, left, mid);
    mergeSort(data, mid + 1, right);
    merge(data, left, mid, right);
}



int main() {
    cout << "Hello, World!" << endl;
    string filename = "/Users/yusrahash/Downloads/billionaire_list_20yrs.csv";
    cout << "1" << endl;
    vector<Billionaire> n = Billionaire::readFromFile(filename);
    mergeSort(n, 0, n.size() - 1);
    for (int i = 0; i < n.size(); i++) {
        if (n[i].getYear() == "2015") {
            n[i].display();
        }
    }
    cout << "2" << endl;

    return 0;
}
