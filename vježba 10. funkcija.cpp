#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;


void processFile(const string& filename, const string& targetWord, const string& targetSubstring)
{
   
    ifstream file(filename);
    vector<string> words(istream_iterator<string>{file}, istream_iterator<string>());

  
    vector<size_t> positions;
    for (size_t i = 0; i < words.size(); ++i) 
    {
        if (words[i] == targetWord) {
            positions.push_back(i);
        }
    }

    
    words.erase(remove_if(words.begin(), words.end(),
        [targetSubstring](const string& str) {
            return str.find(targetSubstring) != string::npos;
        }), words.end());

    
    for_each(words.begin(), words.end(), [](string& str) {
        transform(str.begin(), str.end(), str.begin(), ::toupper);
        });

    
    copy(words.begin(), words.end(), ostream_iterator<string>(std::cout, " "));
}

int main()
{
    const string filename = "words.txt";
    const string targetWord = "target";
    const string targetSubstring = "substring";

    processFile(filename, targetWord, targetSubstring);

    return 0;
}