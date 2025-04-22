#pragma once
#include <vector>
#include "include/crow.h"
#include "billionaire.h"

using namespace std;

void merge(vector<Billionaire>& data, int left, int mid, int right);
void mergeSort(vector<Billionaire>& data, int left, int right);
crow::json::wvalue finalMergeAsJSON(const string& filename, const string& year, int k);

