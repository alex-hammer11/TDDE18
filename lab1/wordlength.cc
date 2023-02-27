#include <fstream>
#include <string>
#include <iostream>

using namespace std;

int main() {
    ifstream in{"data.txt"};
    string word{};
    string longest{};
    string shortest{};
    int words{};
    float avg{};


    in >> word;
   
    if (in.eof()) {
        cout << "The file is empty." << endl;
    } else {

    shortest = word;
    longest = word;
    ++words;
    avg += word.length();


    while (!in.eof()) {
        in >> word;
        in.ignore(1000, ' ');

        if (word.length() > longest.length()) {
            longest = word;
        }

        if (word.length() < shortest.length()) {
            shortest = word;
        }

        avg += word.length();

        ++words;
    }

    cout << "There are " << words << " words in the file." << endl;
    cout << "The shortest word was " << '"' << shortest << '"' << " with " << shortest.length() << " character(s)." << endl;
    cout << "The longest word was " << '"' << longest << '"' << " with " << longest.length() << " character(s)." << endl;
    cout << "The average lenght was " << avg / words << " character(s)." << endl;
    }

    return 0;
}
