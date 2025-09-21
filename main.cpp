/*
Aditya Patra
Arrays Assignment

Purpose:write a program with real-world applications incorporating std::array functions
This program performs and analysis of daily average temperatures during the month of January
*/
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <numeric>
#include <array>
using namespace std;

int main() {
    const int SIZE = 31;
    ifstream fin;
    array<double, SIZE> numbers;
    string month;
    fin.open("array_info.txt");
    if (fin.good( )) {
        fin >> month;
        for(int i = 0; i < SIZE; i++) {
            fin >> numbers[i];
        }
        // print temperatures
        cout << "Analyzing daily average temperature in month of " << month;
        cout << "\nNumber of days recorded: " << numbers.size();
        cout << "\nAverage temperature per day: ";
        for(int i = 0; i < SIZE; i++) {
            cout << numbers.at(i) << ", ";
        }
        cout << "\nIncrease in temperature during month: " << numbers.back() - numbers.front();
        cout << "\nMinimum Temperature: " << *min_element(numbers.begin(), numbers.end());
        cout << "\nMaximum Temperature: " << *max_element(numbers.begin(), numbers.end());
        cout << "\nAverage Temperature: " << accumulate(numbers.begin(), numbers.end(), 0) / numbers.size();
        cout << "\nDays over 15 C: " << count_if(numbers.begin(), numbers.end(), [](int t){ return t >= 15; });
        cout << "\nDays under 15 C: " << count_if(numbers.begin(), numbers.end(), [](int t){ return t < 15; });
        fin.close( );
    }
    else
        cout << "File not found.\n";
}
