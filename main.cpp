/*
 Daily Programmer Challange 319 Condensing Sentences
 Description: This program takes in a sentence and condenses it
 Input: A sentence
 Output: A condensed version of that sentence
 Example:
    Input:
    I heard the pastor sing live verses easily.
    Output:
    I heard the pastor sing liverses easily.

    Input:
    Digital alarm clocks scare area children.
    Output:
    Digitalarm clockscarea children.
 */

#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int main()
{
    string userInput = "";
    string firstWord = "";
    string nextWord = "";
    string temp = "";
    vector<string> words;
    istringstream iss;

    cout << "Enter the string you would like to condense: " << endl;
    getline(cin, userInput);
    iss.str(userInput);
    while(iss >> temp)
        words.push_back(temp);

    for(unsigned int i = 0; i < words.size() - 1; i++)
    {
        firstWord = words.at(i);
        nextWord = words.at(i + 1);
        for(unsigned int j = 0; j < firstWord.size(); j++)
        {
            temp = firstWord.substr(j);
            if(nextWord.find(temp) == 0) //if substr was found at the beginning of the next word...
            {
                words.at(i) += nextWord.replace(0, temp.size(), "");
                words.erase(words.begin() + (i + 1));
                i--; //we need to check the new word we just created as well
                break;
            }
        }
    }

    for(const auto& word : words)
    {
        cout << word << " ";
    }
    cout << endl;

    return 0;
}