#include <iostream>
#include <fstream>
#include <string>
#include <chrono>


using namespace std;
int main()
{
    string half1, half2, full;
    string bp1, bp2, bp3;
    int n = 0, g = 0;
    ifstream file("day3.txt");
    while (getline(file, full)) {
        half1 = full.substr(0, full.length() / 2);
        half2 = full.substr(full.length() / 2);

        for (char& c : half1) {
            if (half2.find(c) != string::npos) {
                int i = c; //Coverts the character into the ascii code, A-Z 65-90 and a-z 95-121 and substract the excess numbers
                if (c < 91) {
                    i = i - 64 + 26; //Value of ascii code - number of positions to get 1 + 26(going into uppercase alphabet)
                    n = n + i;
                    break;
                }
                if (c > 92) {
                    i = i - 96;
                    n = n + i;
                    break;
                }
            }
        }
        
        
    }
    file.close();
    //Part 2
    ifstream file2("day3.txt");{
        while (file2 >> bp1 >> bp2 >> bp3) {
            for (char& d : bp1) {
                if (bp2.find(d) != string::npos && bp3.find(d) != string::npos) {
                    int j = d; //Coverts the character into the ascii code, A-Z 65-90 and a-z 95-121 and substract the excess numbers
                    
                    if (d < 91) {
                        j = j - 64 + 26; //Value of ascii code - number of positions to get 1 + 26(going into uppercase alphabet)
                        g = g + j;

                        break;
                    }
                    if (d > 92) {
                        j = j - 96;
                        g = g + j;
                        break;
                    }
                }
            }
        }
    }
    cout <<"part1 " << n << endl;
    cout <<"part2 " << g << endl;
}
