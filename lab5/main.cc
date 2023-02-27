#include <iostream>
#include <fstream>
#include <iterator>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>

using our_pair = std::pair<std::string, int>;

struct
{
    bool operator()(our_pair const &a, our_pair const &b) const { return a.second > b.second; }
} sortFrequency;

struct
{
    bool operator()(our_pair const &a, our_pair const &b) const { return a.first < b.first; }
} sortLexicographical;

std::vector<our_pair> createPairVector(std::vector<std::string> const &text)
{
    std::vector<our_pair> vec{};
    std::transform(text.begin(), text.end(), std::back_inserter(vec),
                   [&text](const std::string &word)
                   {
                       return std::make_pair(word, int(std::count(text.begin(), text.end(), word)));
                   });
    return vec;
}

void printTable(std::vector<our_pair> const &vec, bool const &freq)
{
    auto longestWord = std::max_element(vec.begin(), vec.end(), [](our_pair const &p1, our_pair const &p2)
                                        { return p1.first.size() < p2.first.size(); });

    our_pair pairWithLongestWord = *longestWord;

    std::cout << std::setfill(' ');

    // The int has width 3 to account for words occuring more than 9 times and becoming double digits
    auto printPair = [&pairWithLongestWord, &freq](const our_pair &p)
    { if (freq) {std::cout << std::setw(pairWithLongestWord.first.size()) << std::right << p.first << std::setw(3) << std::right << p.second << std::endl;}
    else {std::cout << std::setw(pairWithLongestWord.first.size()) << std::left << p.first << std::setw(3) << std::right << p.second << std::endl;} };

    std::for_each(vec.begin(), vec.end(), printPair);

    std::cout << std::endl;
}

void frequency(std::vector<std::string> const &text)
{
    std::vector<our_pair> freq{createPairVector(text)};

    std::sort(freq.begin(), freq.end(), sortFrequency);

    freq.erase(std::unique(freq.begin(), freq.end()), freq.end());

    printTable(freq, true);
}

void table(std::vector<std::string> const &text)
{
    std::vector<our_pair> lex{createPairVector(text)};

    std::sort(lex.begin(), lex.end(), sortLexicographical);

    lex.erase(std::unique(lex.begin(), lex.end()), lex.end());

    printTable(lex, false);
}

void substitute(std::vector<std::string> &text, std::string const &old_word, std::string const &new_word)
{
    std::replace(text.begin(), text.end(), old_word, new_word);
}

void remove(std::vector<std::string> &text, std::string const &word)
{
    auto it = std::remove(text.begin(), text.end(), word);
    text.erase(it, text.end());
}

void print(std::vector<std::string> const &text)
{
    std::ostream_iterator<std::string> cout_it(std::cout, " ");
    std::copy(text.begin(), text.end(), cout_it);
    std::cout << "\n"
              << std::endl;
}

void argument_helper(std::vector<std::string> &text, std::string const &argument)
{
    std::string splitted_argument = argument.substr(0, argument.find("="));
    int equal_sign = argument.find("=");
    int plus_sign = argument.find("+");
    if (splitted_argument == "--print")
    {
        print(text);
    }
    else if (splitted_argument == "--table")
    {
        table(text);
    }
    else if (splitted_argument == "--frequency")
    {
        frequency(text);
    }
    else if (splitted_argument == "--substitute")
    {
        std::string old_word{argument.substr(equal_sign + 1, plus_sign - equal_sign - 1)};
        std::string new_word{argument.substr(plus_sign + 1, argument.length() - plus_sign - 1)};
        substitute(text, old_word, new_word);
    }
    else if (splitted_argument == "--remove")
    {
        remove(text, argument.substr(equal_sign + 1, argument.length()));
    }
    else
    {
        std::cout << "Wrong argument, flag doesn't exist" << std::endl;
    }
}

int main(int argc, char **argv)
{
    std::vector<std::string> arguments(argv + 1, argv + argc);

    std::ifstream file;
    try
    {
        file.open(arguments.at(0));
        if (file.fail())
        {
            throw(std::string("The file you have entered does not exist. \nPlease try again!"));
        }

        if (argc == 2)
        {
            std::cout << "No arguments given" << std::endl
                      << "Possible arguments are:" << std::endl
                      << "'--print' - prints the text to the terminal" << std::endl
                      << "'--table' - prints all the words in lexicographical order and number of occurences in a table format" << std::endl
                      << "'--frequency' - prints all the words sorted by number of occurences in the text" << std::endl
                      << "'--substitute=<word_to_substitute>+<new_word> - substitutes a given word with the new word of your choosing" << std::endl
                      << "'--remove=<word_to_remove> - removes a given word of your choosing" << std::endl
                      << std::endl
                      << "The order of flags are sequential in the order they are given, where different orders of flags gives different outputs" << std::endl;
        }
        else
        {
            // To make sure that the text file is not passed as an argument
            arguments.erase(arguments.begin());

            std::vector<std::string> text{};
            std::istream_iterator<std::string> first(file);
            std::istream_iterator<std::string> last;

            std::copy(first, last, std::back_inserter(text));

            std::for_each(arguments.begin(), arguments.end(), [&text](std::string const &s)
                          { argument_helper(text, s); });

            file.close();
        }
    }
    catch (std::string const &argument)
    {
        std::cout << argument << std::endl;
    }
    return 0;
}
