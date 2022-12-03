#include <iostream>
#include <fstream>
#include <string>

using namespace std;
int main()
{

    long score = 0;
    long score2 = 0;
    string b;

    ifstream file("day2.txt");
    while (getline(file, b)) {
        if (b == "A X") {
            score = score + 4;
            score2 = score2 + 3;
        }
        if (b == "A Y") {
            score = score + 8;
            score2 = score2 + 4;
        }
        if (b == "A Z") {
            score = score + 3;
            score2 = score2 + 8;
        }
        if (b == "B X") {
            score = score + 1;
            score2 = score2 + 1;
        }
        if (b == "B Y") {
            score = score + 5;
            score2 = score2 + 5;
        }
        if (b == "B Z") {
            score = score + 9;
            score2 = score2 + 9;
        }
        if (b == "C X") {
            score = score + 7;
            score2 = score2 + 2;
        }
        if (b == "C Y") {
            score = score + 2;
            score2 = score2 + 6;
        }
        if (b == "C Z") {
            score = score + 6;
            score2 = score2 + 7;
        }
        
    }
    cout << score << endl;
    cout << score2 << endl;
}
     
