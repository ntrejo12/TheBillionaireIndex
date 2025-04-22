#pragma once
#include <vector>
#include "include/crow.h"
#include "billionaire.h"

bool isAllDigits(const std::string& s);
void heapify(std::vector<Billionaire>& array, int size, int root);
void heapSortVec(std::vector<Billionaire>& array);
void HeapSort(const std::string& filename, const std::string& year, int k);
crow::json::wvalue heapSortDurationAsJSON(const std::string& filename, const std::string& year, int k);

