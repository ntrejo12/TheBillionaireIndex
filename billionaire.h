//
// Created by Yusra Hash on 4/19/25.
//
#ifndef MERGE_H
#define MERGE_H
#endif //MERGE_H

#include <iostream>
#include <string>
using namespace std;

class Billionaire {
public:
    string name;
    int year;
    double networth;
    char gender;
    int age;
    string company;
    string country;
private:
    Billionaire(string name, int year, double networth, char gender, int age, string company, string country) {
        this->name = name;
        this->year = year;
        this->networth = networth;
        this->gender = gender;
        this->age = age;
        this->company = company;
        this->country = country;
    }
    string getName() {
        return name;
    }
    int getYear() {
        return year;
    }
    double getNetworth() {
        return networth;
    }
    char getGender() {
        return gender;
    }
    int getAge() {
        return age;
    }
    string getCompany() {
        return company;
    }
    string getCountry() {
        return country;
    }
    void display() {
        cout << "Name: " << getName() << endl;
        cout << "Year: " << getYear() << endl;
        cout << "Networth: " << getNetworth() << endl;
        cout << "Gender: " << getGender() << endl;
        cout << "Age: " << getAge() << endl;
        cout << "Company: " << getCompany() << endl;
        cout << "Country: " << getCountry() << endl;
    }
};