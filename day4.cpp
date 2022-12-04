#include <iostream>
#include <fstream>
#include <string>


using namespace std;
int main()
{
    int loc = 0, loc2=0;
    string full;
    ifstream file("day4.txt"); 
    while (getline(file, full)) {
        int range[4] = { 0,0,0,0 };
        size_t range_idx = 0;
        for (size_t i = 0; i < full.length(); i++) {
            char c = full[i];
            if (c == '-' || c == ',') {
                range_idx += 1;
            }
            else {
                char digit = c - '0';
                range[range_idx] = range[range_idx] * 10 + digit;
            }
        }
        if (range[0] == range[2] || range[1] == range[3] || (range[0] < range[2] && range[1] > range[3]) || (range[0] > range[2] && range[1] < range[3])) {
            loc = loc + 1;
        }
        if (range[0] == range[2] || range[1] == range[3] || (range[0] < range[2] && range[1] >= range[2]) || (range[0] > range[2] && range[0] <= range[3])) {
            loc2 = loc2 + 1;
        }
    }
    cout << "part 1: " << loc << endl;
    cout << "part 2: " << loc2;
}
