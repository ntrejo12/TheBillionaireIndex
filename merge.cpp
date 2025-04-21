#include "billionaire.h"
#include <string>
#include <vector>
#include <iostream>
#include <chrono>
using namespace chrono;
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


void finalMerge(string filename, string year, int  k) {
    auto start = high_resolution_clock::now();
    auto allRecords = Billionaire::readFromFile(filename);
    vector<Billionaire> updatedData;
    for (int i = 1; i < allRecords.size(); i++) {
        if (allRecords[i].getName() ==allRecords[i-1].getName()) {
            continue;
        }
        updatedData.push_back(allRecords[i]);
    }
    int tracker = 0;
    mergeSort(updatedData, 0, updatedData.size() - 1);
    for (int i = 0; i < allRecords.size(); i++) {
        if (updatedData[i].getYear() == year) {
            cout << endl;
            updatedData[i].display();
            tracker++;
        }
        if (tracker == k) {
            break;
        }
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << endl;
    cout << "Merge Sort Duration: " << duration.count() << " microseconds" << endl;
}

int main() {
    string year;
    int k;
    // make sure data is included in the project folder.
    const string filename = "/Users/yusrahash/Downloads/billionaire_list_20yrs.csv";
    cout << "Using data file: " << filename << "\n";
    cout << "Enter year: "; cin >> year;
    cout << "Enter k: "; cin >> k;

    finalMerge(filename, year, k);
    return 0;
}

/*int main() {
    cout << "Hello, World!" << endl;
    string filename = "/Users/yusrahash/Downloads/billionaire_list_20yrs.csv";
    cout << "1" << endl;
    vector<Billionaire> n = Billionaire::readFromFile(filename);
    mergeSort(n, 0, n.size() - 1);
    int counter = 0;
    for (int i = 0; i < n.size(); i++) {
        if (n[i].getYear() == "2015") {
            n[i].display();
            counter++;
        }
    }
    cout << counter << endl;
    cout << "2" << endl;

    return 0;
}
*/
