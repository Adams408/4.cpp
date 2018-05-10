/*
 * Author: James Adams
 * Date: April 20, 2018
 * File: 4.cpp
 */

#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

string itos(int n) {
    string a[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    string b[] = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
    string c[] = {"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
    string d[] = {"hundred","thousand","million","billion"};

    if (n < 10) {
        return a[n];
    }
    if (n < 20) {
        return b[n - 10];
    }
    if (n >= 20 && n < 100) {
        if (n % 10 == 0) {
            return c[n / 10];
        } else {
            return c[n / 10] + a[n % 10];
        }
    }
    if(n >= 100 && n < 1000){
        if (n % 10 == 0) {
            return a[n / 100] + d[0];
        } else {
            return a[n / 100] + d[0] + "_" + itos(n - (n/100 * 100));
        }
    }
    if(n >= 1000 && n < 10000){
        if (n % 10 == 0) {
            return a[n / 1000] + d[1];
        } else {
            return a[n / 1000] + d[1] + "_" + itos(n - (n / 1000 * 1000));
        }
    }
    return a[0];
}

int main(int argc, char* argv[]) {
    for (int i = 1; i < argc; i++) {
        int n = atoi(argv[i]);
        cout << "file " << itos(n) << ".txt" << endl;
    }
    return 0;
}