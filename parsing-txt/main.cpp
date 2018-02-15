//
// Created by Shidfar Hodizoda on 15/02/2018.
//

#include <fstream>
#include <iostream>

using namespace std;

int main()
{
    string filename = "stats.txt";
    ifstream input;

    input.open(filename);

    if (!input.is_open()) return 1;

    while (input)
    {
        string line;

        getline(input, line, ':');

        int population;
        input >> population;

//        input.get(); // <- reads one character
        line.erase(std::remove(line.begin(), line.end(), '\n'),
                   line.end()); // <- removes new lines

        line.erase(std::remove(line.begin(), line.end(), '\t'),
                   line.end()); // <- removes tabs

        input >> ws; // <- reading whitespaces

        if (!input) break;

        cout <<"'" <<line <<"'" <<" - '" <<population <<"'" <<endl;
    }
    input.close();

    return 0;
}