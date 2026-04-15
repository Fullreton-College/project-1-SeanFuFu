#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

// get all words from a file
void getWords(vector<string> &words, ifstream &file);
// remove comma and become lower case
void standardizingWord(string &word);
// count the exact word from a list of words
int countWord(vector<string> &words, string targetWord);
// check if repeat again
bool askRepeating();

int main()
{
    string filename = "homes.txt";
    // get the file
    ifstream file(filename);
    // get all words from the file
    vector<string> wordsFromTheFile;
    getWords(wordsFromTheFile, file);
    // close the file
    file.close();

    do
    {
        string tagetWord;
        // get the target word
        cout << "What word that you want to find from  " << filename << " about the frequency of the words used in the file?" << endl;
        getline(cin, tagetWord);
        standardizingWord(tagetWord);
        // count the word
        int count = countWord(wordsFromTheFile, tagetWord);
        // print the result
        cout << "the word, \"" << tagetWord << "\", is used " << count << " times in " << filename << endl;
        cout << endl;

    } while (askRepeating());

    return 0;
}

void getWords(vector<string> &words, ifstream &file)
{
    string line;
    while (getline(file, line))
    {
        stringstream lineWords(line);
        string word;
        while (getline(lineWords, word, ' '))
        {
            standardizingWord(word);
            words.push_back(word);
        }
    }
}

void standardizingWord(string &word)
{
    // become lower case
    transform(word.begin(), word.end(), word.begin(), ::tolower);
    // remove punctuation
    if (!isalpha(word.back()))
    {
        word = word.substr(0, word.size() - 1);
    }
    if (!isalpha(word.front()))
    {
        word = word.substr(1, word.size());
    }
}

int countWord(vector<string> &words, string targetWord)
{
    int count = 0;
    for (string word : words)
    {
        if (word == targetWord)
        {
            count++;
        }
    }
    return count;
}

bool askRepeating()
{
    char c;
    cout << "Do you want to check another word? (Y/N)" << endl;
    cin >> c;
    if (c == 'Y' || c == 'y')
    {
        return true;
    }
    return false;
}