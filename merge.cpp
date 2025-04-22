#include "billionaire.h"
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <chrono>
using namespace chrono;
using namespace std;


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

//following merge code from geeksforgeeks
//https://www.geeksforgeeks.org/merge-sort/

//merges two subarrays of data[],
//first subarray is data[left to mid], second subarray is data[mid+1 to right]
void merge(vector<Billionaire>& data, int left, int mid, int right) {

    int n1 = mid - left + 1;
    int n2 = right - mid;

    //create 2 temp vectors
    vector<Billionaire> L(n1), R(n2);

    //copy the data to temp vectors L[] and R[]
    for (int i = 0; i < n1; i++) {
        L[i] = data[i + left];
    }
    for (int i = 0; i < n2; i++) {
        R[i] = data[i + mid + 1];
    }
    int i = 0, j = 0;
    int k = left;

    //merge the temp vectors back into data[left..right]
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

    //copy any remaining elements of L[]
    while (i < n1) {
        data[k] = L[i];
        i++;
        k++;
    }

    //copy any remaining elements of R[]
    while (j < n2) {
        data[k] = R[j];
        j++;
        k++;
    }
}

// begins at left index abd ends at right index of the sub-array of data to be sorted
void mergeSort(vector<Billionaire>& data, int left, int right) {
    if (left >= right) {
        return;
    }
    int mid = left + (right - left) / 2;
    mergeSort(data, left, mid);
    mergeSort(data, mid + 1, right);
    merge(data, left, mid, right);
}

//function that calls merge and mergeSort and displays the k richest people
void finalMerge(string filename, string year, int  k) {
    //timer for merge sort starts
    auto start = high_resolution_clock::now();

    //the csv file is read and the data is put into a vector
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
    for (auto& kv : bestByName) {
        filtered.push_back(kv.second);
    }

    // if the result is empty, output message for the user
    if (filtered.empty()) {
        cout << "No valid data for year " << year << "\n";
        return;
    }

    // filtering the data in ascending order
    mergeSort(filtered, 0, filtered.size() - 1);

    // printing the top k richest in the user-selected year
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
    //timer for merge sort stops
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << endl;

    //merge sort duration is printed in microseconds
    cout << "Merge Sort Duration: " << endl;
    cout << duration.count() << " microseconds" << endl;

}

int main() {
    string year;
    int k;
    const string filename = "billionaire_list_20yrs.csv";
    cout << "Using data file: " << filename << "\n";

    //user enters a year and k value
    cout << "Enter year: "; cin >> year;
    cout << "Enter k: "; cin >> k;

    //merge sort will occur with the given parameters
    finalMerge(filename, year, k);
    return 0;
}