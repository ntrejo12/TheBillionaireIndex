
// Created by Yusra Hash on 4/19/25.
//
#ifndef MERGE_H
#define MERGE_H
#endif //MERGE_H
#include <sstream>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Billionaire {
private:
    string name;
    string year;
    string networth;
    string age;
    string company;
    string country;
public:
    Billionaire() {
        name = "";
        year = "";
        networth = "";
        age = "";
        company = "";
        country = "";
    }
    Billionaire(string name, string year, string networth, string age, string company, string country) {
        this->name = name;
        this->year = year;
        this->networth = networth;
        this->age = age;
        this->company = company;
        this->country = country;
    }
    string getName() const{
        return name;
    }
    string getYear() const{
        return year;
    }
    string getNetworth() const{
        return networth;
    }

    string getAge() const{
        return age;
    }
    string getCompany() const{
        return company;
    }
    string getCountry() const{
        return country;
    }
    void display() {
        int counter = 0;
        cout << "Name: " << getName() << endl;
        cout << "Year: " << getYear() << endl;
        cout << "Networth: " << getNetworth() << endl;
        cout << "Age: " << getAge() << endl;
        cout << "Company: " << getCompany() << endl;
        cout << "Country: " << getCountry() << endl;
    }

    bool operator<=(const Billionaire &other) {
        return this->networth <= other.networth;
    }
    static vector<Billionaire> readFromFile(string filename) {
        int count = 0;
        vector<Billionaire> billionaireList;
        ifstream file(filename);
        if (!file.is_open()) {
            cerr << "Error opening file: " << filename << endl;
        }
        string line;
        string temp, tempName, tempYear, tempNetworth, tempAge, tempCompany, tempCountry;
        while (getline(file, line)) {
            count++;
            if (count >= 2) {
                stringstream ss(line);
                getline(ss, temp, ',');
                getline(ss, tempName, ',');
                getline(ss, temp, ',');
                getline(ss, tempAge, ',');
                getline(ss, temp, ',');
                getline(ss, tempYear, ',');
                getline(ss, tempCountry, ',');
                getline(ss, tempCompany, ',');
                getline(ss, temp, ',');
                getline(ss, temp, ',');
                getline(ss, temp, ',');
                getline(ss, temp, ',');
                getline(ss, temp, ',');
                getline(ss, temp, ',');
                getline(ss, tempNetworth, ',');
                getline(ss, temp, ',');
                getline(ss, temp, ',');
                getline(ss, temp, ',');

                Billionaire tempBillionaire(tempName, tempYear, tempNetworth, tempAge, tempCompany, tempCountry);
                billionaireList.push_back(tempBillionaire);
            }
        }
        return billionaireList;
    }



};