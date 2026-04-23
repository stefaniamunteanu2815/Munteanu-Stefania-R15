#include <iostream>
#include <fstream>
#include <string>
#include <map> 
#include <queue>
#include <utility>
using namespace std;

struct WordEntry 
{
    string word;
    int count;
    bool operator<(const WordEntry& other) const 
    {
        if (count != other.count) return count < other.count;
        return word > other.word;
    }
};

int main() 
{
    ifstream file("Input.txt");
    string phrase, line;
    while (getline(file, line)) 
    {
        phrase += line + " ";
    }
    file.close();
    map<string, int> counts;
    string separators = " ,?!.";

    size_t start = phrase.find_first_not_of(separators);
    while (start != string::npos) 
    {
        size_t end = phrase.find_first_of(separators, start);
        string word = phrase.substr(start, (end == string::npos) ? string::npos : end - start);
        for (size_t i = 0; i < word.length(); i++) 
        {
            word[i] = tolower((unsigned char)word[i]);
        }
        if (!word.empty()) 
        {
            counts[word]++;
        }
        start = phrase.find_first_not_of(separators, end);
    }
    priority_queue<WordEntry> pq;
    for (map<string, int>::iterator it = counts.begin(); it != counts.end(); it++)
    {
        WordEntry temp;
        temp.word = it->first;
        temp.count = it->second;
        pq.push(temp);
    }

    while (!pq.empty()) 
    {
        WordEntry top = pq.top();
        cout << top.word << " => " << top.count << endl;
        pq.pop();
    }
    return 0;
}
