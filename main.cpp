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
    bool found = false;

    cout << "Enter the string you would like to condense: " << endl;
    getline(cin, userInput);
    iss.str(userInput);
    while(iss >> temp)
        words.push_back(temp);

    for(int i = 0; i < words.size() - 1;) //only increment if there wasn't a match
    {
        found = false;
        firstWord = words.at(i);
        nextWord = words.at(i + 1);
        for(int j = 0; j < firstWord.size(); j++)
        {
            temp = firstWord.substr(j);
            if(nextWord.find(temp) == 0)
            {
                found = true;
                words.at(i) += nextWord.replace(0, temp.size(), "");
                words.erase(words.begin() + (i + 1));
            }
            if(found) break;
        }
        if(!found)
        {
            i++;
        }
    }

    for(const auto& word : words)
    {
        cout << word << " ";
    }
    cout << endl;

    return 0;
}