#include <iostream>
#include <iomanip>

using namespace std;

int main() {

  cout.precision(3);
  cout.setf(ios::fixed, ios::floatfield);

  cout << "Enter one integer: ";
  int int_num{};
  cin >> int_num;
  cout << "You entered the number: " << int_num << endl;
  cin.ignore(1000, '\n');

  cout << endl;

  cout << "Enter 4 integer: ";
  cin >> int_num;
  cout << "You have entered the numbers: " << int_num << " ";
  cin >> int_num;
  cout << int_num << " ";
  cin >> int_num;
  cout << int_num << " ";
  cin >> int_num;
  cout << int_num << endl;
  cin.ignore(1000, '\n');

  cout << endl;

  cout << "Enter one integer and one real number: ";
  cin >> int_num;
  float real_num{};
  cin >> real_num;
  cout << "The real is: " << setw(8) << real_num << endl;
  cout << "The int_num is: " << setw(5) << int_num  << endl;
  cin.ignore(1000, '\n');

  cout << endl;

  cout << "Enter one real number and one integer number: ";
  cin >> real_num;
  cin >> int_num;
  cout << setfill('.')  << "The real is: " << setw(10) << real_num << "\n"
       << "The integer is: " << setw(7) << int_num << endl;
  cin.ignore(1000, '\n');

  cout << endl;

  cout << "Enter a character: ";
  char character{};
  cin >> character;
  cout << "You have entered the character: " << character << endl;
  cin.ignore(1000, '\n');

  cout << endl;

  cout << "Enter a word: ";
  string word{};
  cin >> word;
  cout << "The word '" << word << "' has " << word.length() << " characters" << endl;
  cin.ignore(1000, '\n');

  cout << endl;

  cout << "Enter an integer and a word: ";
  cin >> int_num;
  cin >> word;
  cout << "You have entered '" << int_num << "' and '" << word << "'." << endl;
  cin.ignore(1000, '\n');

  cout << endl;

  cout << "Enter an character and a word: ";
  cin >> character;
  cin >> word;
  cout << "You have entered the string " << '"' << word << '"' << " and the character " << "'" << character << "'" << endl;
  cin.ignore(1000, '\n');

  cout << endl;

  cout << "Enter a word and a real number: ";
  cin >> word;
  cin >> real_num;
  cout << "You entered " << '"' << word << '"' << " and " << '"' << real_num << '"' << endl;
  cin.ignore(1000, '\n');

  cout << endl;

  cout << "Enter a textline: ";
  getline(cin, word);
  cout << "You have entered: " << '"' << word << '"' << endl;

  cout << endl;

  cout << "Enter a second line of text: ";
  getline(cin, word);
  cout << "You have entered: " << '"' << word << '"' << endl;

  cout << endl;

  cout << "Enter three words: ";
  cin >> word;
  cout << "You have entered: " << "'" << word << " ";
  cin >> word;
  cout << word << " ";
  cin >> word;
  cout << word << "'" << endl;
  cin.ignore(1000, '\n');

  return 0;
}
