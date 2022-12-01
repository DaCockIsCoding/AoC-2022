#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <fstream>

using namespace std;
int main() {
    vector<int> cal = { 0 };
    ifstream file("day1.txt");
    string line;
    while (getline(file, line)) {
        if (line == "") {
            cal.push_back(0);
        }
        else {
            cal.back() += stoi(line);
        }
    }

    partial_sort(cal.begin(), cal.begin() + 3, cal.end(), greater<int>{});
    cout << "Part 1: " << cal[0] << '\n';
    cout << "Part 2: " << accumulate(cal.begin(), cal.begin() + 3, 0) << '\n';

    return 0;
}