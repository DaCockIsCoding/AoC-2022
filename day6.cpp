#include <iostream>
#include <fstream>
#include <string>
#include <set>

using namespace std;

int findFirstMarker(const string& data) {
    string c;
    for (int i = 0; i < data.size(); ++i) {
        c += data[i];
        if (c.size() > 4) {
            c.erase(c.begin());
        }
        if (c.size() == 4 && c[0] != c[1] && c[0] != c[2] && c[0] != c[3] && c[1] != c[2] && c[1] != c[3] && c[2] != c[3]) {
            return i + 1;
        }
    }
}

int findFirstMessageMarker(const string& data) {
    string c;
    for (int i = 0; i < data.size(); ++i) {
        c += data[i];
        if (c.size() > 14) {
            c.erase(c.begin());
        }
        set<char> s(c.begin(), c.end());
        if (c.size() == 14 && s.size() == 14) {
            return i + 1;
        }
    }
}


int main() {
    ifstream file("day6.txt");
    string data;
    file >> data;
    int sol1 = findFirstMarker(data);
    cout << "part 1: " << sol1 << endl;
    int sol2 = findFirstMessageMarker(data);
    cout << "part 2: " << sol2 << endl;
    return 0;
}
