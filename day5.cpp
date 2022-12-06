#include <fstream>
#include <iostream>
#include <string>

using namespace std;


int main()
{
    string c, stack[10];

    ifstream file("day5.txt");

    // Part 1:
    while (getline(file, c)) {
        if (isdigit(c[1])) {
            break;
        }

        for (int pos = 1, i = 0; pos < c.length(); ++i, pos += 4) {
            if (isalpha(c[pos])) {
                stack[i] += c[pos];
            }
        }
    }

    for (auto& s : stack) {
        reverse(s.begin(), s.end());
    }

    while (getline(file, c)) {
        if (c.length() == 0) {
            continue;
        }

        int howMany, from, to;
        sscanf_s(c.c_str(), "move %d from %d to %d", &howMany, &from, &to);

        --from;
        --to;

        for (int i = 0; i < howMany; ++i) {
            stack[to].push_back(stack[from].back());
            stack[from].erase(stack[from].length() - 1);
        }
        
    }

    string sol = "";
    for (auto& s : stack) {
        if (s.length() > 0) {
            sol += s.back();
        }
    }

    cout << "Part 1: " << sol << endl;

    
    // Part 2:
    for (auto& s : stack) {
        s.clear();
    }
    file.clear();
    file.seekg(0);

    while (getline(file, c)) {
        if (isdigit(c[1])) {
            break;
        }

        for (int pos = 1, i = 0; pos < c.length(); ++i, pos += 4) {
            if (isalpha(c[pos])) {
                stack[i] += c[pos];
            }
        }
    }

    for (auto& s : stack) {
        reverse(s.begin(), s.end());
    }

    while (getline(file, c)) {
        if (c.length() == 0) {
            continue;
        }

        int howMany, from, to;
        sscanf_s(c.c_str(), "move %d from %d to %d", &howMany, &from, &to);

        --from;
        --to;

        stack[to] += stack[from].substr(stack[from].length() - howMany);

        stack[from].erase(stack[from].length() - howMany);
    }

    string sol2 = "";
    for (auto& s : stack) {
        if (s.length() > 0)
            sol2 += s.back();
    }


cout << "Part 2: " << sol2 << endl;

return 0;
}
