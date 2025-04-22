//
// Created by Qingqi (Quinn)  Yuan on 4/18/25.
//

#include "billionaire.h"
#include <vector>
#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <cctype>
#include "include/crow.h"
#include <chrono>
using namespace std;
using namespace chrono;

// A helper function
// returns true if s is nonempty and every character in s is a digit
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

// ensuring the subtree rooted at the root index.
void heapify(vector<Billionaire>& array, int size, int root) {
    int largest = root;
    long long rootWorth;

    if (isAllDigits(array[root].getNetworth())) {
        rootWorth = stoll(array[root].getNetworth());
    } else {
        rootWorth = 0;
    }
    int left = 2*root + 1, right = 2*root + 2;

    // if there is left child, parse and compare
    if (left < size) {
        long long leftWorth;
        if (isAllDigits(array[left].getNetworth())) {
            leftWorth = stoll(array[left].getNetworth());
        } else {
            leftWorth = 0;
        }

        if (leftWorth > rootWorth) {
            largest = left;
            rootWorth = leftWorth;
        }
    }

    // if there is right child, parse and compare
    if (right < size) {
        long long rightWorth;
        if (isAllDigits(array[right].getNetworth())) {
            rightWorth = stoll(array[right].getNetworth());
        } else {
            rightWorth = 0;
        }
        if (rightWorth > rootWorth) {
            largest = right;
        }
    }
    // if the largest element is not the root, swap and recurse
    if (largest != root) {
        swap(array[root], array[largest]);
        heapify(array, size, largest);
    }
}


void heapSortVec(vector<Billionaire>& array) {
    int n = (int) array.size();
    for (int root = n / 2 - 1; root >= 0; root--) {
        heapify(array, n, root);
    }
    for (int end = n - 1; end > 0; end--) {
        swap(array[0], array[end]);
        heapify(array, end, 0);
    }
}

void HeapSort(const string& filename, const string& year, int k) {
    // for the timing:
    auto start = high_resolution_clock ::now();
    // loading data
    auto allRecords = Billionaire::readFromFile(filename);

    // because the data has duplicated info for the same person,
    // we keep the richest data they have for the given year
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

    // preparing for sorting
    vector<Billionaire> filtered;
    filtered.reserve(bestByName.size());
    for (const auto& [_, record] : bestByName) {
        filtered.push_back(record);
    }

    // if the result is empty, output message for the user
    if (filtered.empty()) {
        cout << "No valid data for year " << year << "\n";
        return;
    }

    // filtering the data in ascending order
    heapSortVec(filtered);

    // printing the top k richest in the user-selected year
    cout << "\n[Heap Sort] Top " << k << " richest in " << year << ":\n";
    int printed = 0;
    int n = (int)filtered.size();
    int rank = 0;
    // printing the rank of billionaires.
    for (int idx = n - 1; idx >= 0 && printed < k; idx--, printed++) {
        rank ++;
        cout << endl;
        cout << rank<< ". ";
        filtered[idx].display();
    }
    // stop the timer and display the amount of time the heap sort takes
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop-start);
    cout<<"\nHeap Sort Duration: "<<duration.count()<<" microseconds.\n";

}

crow::json::wvalue heapSortDurationAsJSON(const string& filename, const string& year, int k) {
    auto start = high_resolution_clock::now();
    auto allRecords = Billionaire::readFromFile(filename);

    unordered_map<string, Billionaire> bestByName;
    for (const auto& record : allRecords) {
        if (record.getYear() != year || !isAllDigits(record.getNetworth())) continue;

        long long worth = stoll(record.getNetworth());
        auto it = bestByName.find(record.getName());

        if (it == bestByName.end() || worth > stoll(it->second.getNetworth())) {
            bestByName[record.getName()] = record;
        }
    }

    vector<Billionaire> filtered;
    for (auto& kv : bestByName) {
        filtered.push_back(kv.second);
    }

    heapSortVec(filtered);

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    crow::json::wvalue result;
    result["duration_microseconds"] = duration.count();
    return result;
}


// int main() {
//     string year;
//     int k;
//     // make sure data is included in the project folder.
//     const string filename = "billionaire_list_20yrs.csv";
//     cout << "Using data file: " << filename << "\n";
//     cout << "Enter year:        "; cin >> year;
//     cout << "Enter k:           "; cin >> k;
//
//     HeapSort(filename, year, k);
//     return 0;
// }