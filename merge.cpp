#include "billionaire.h"
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <chrono>
using namespace chrono;
using namespace std;



static bool isAllDigits(const string& s) {
    if (s.empty()) {
        return false;
    }
    for (char c : s) {
        unsigned char uc = static_cast<unsigned char>(c);

        if (!isdigit(uc)) {
            return false;
        }
    }
    return true;
}

//following merge code from geeksforgeeks
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
        long long LNetworth = stoll(L[i].getNetworth());
        long long RNetworth = stoll(R[j].getNetworth());
        if (LNetworth<= RNetworth) {
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
        k++;
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
    unordered_map<string, Billionaire> bestByName;
    for (const auto& record : allRecords) {
        if (record.getYear() != year || !isAllDigits(record.getNetworth())) {
            continue;
        }
        long long worth = stoll(record.getNetworth());
        auto it = bestByName.find(record.getName());
        if (it == bestByName.end()) {
            bestByName[record.getName()] = record;
        }else {
            long long existingWorth = stoll(it->second.getNetworth());
            if (worth > existingWorth) {
                bestByName[record.getName()] = record;
            }
        }
    }

    vector<Billionaire> filtered;
    filtered.reserve(bestByName.size());
    for (auto& kv : bestByName) {
        filtered.push_back(kv.second);
    }
    if (filtered.empty()) {
        cout << "No valid data for year " << year << "\n";
        return;
    }
    mergeSort(filtered, 0, filtered.size() - 1);
    cout << "\n[Merge Sort] Top " << k << " richest in " << year << ":\n";
    int printed = 0;
    int n = (int)filtered.size();
    int rank =0;
    for (int idx = n - 1; idx >= 0 && printed < k; --idx, ++printed) {
        rank++;
        cout << endl;
        cout << rank << ". ";
        filtered[idx].display();
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
