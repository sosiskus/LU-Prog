#include <cstdlib>
#include <ctime>
#include <iostream>
#include <map>
#include <string>
#include <vector>

void print(const std::map<std::string, int> &wordCount)
{
    std::cout << "MAP: ";
    for (const auto &pair : wordCount)
    {
        std::cout << pair.first << ": " << pair.second << "  ";
    }
    std::cout << std::endl;
}

int main()
{
    std::vector<std::string> words;
    std::vector<std::string> possibleWords = {"apple", "banana", "cherry", "date", "elderberry",
                                              "fig", "grape", "honeydew", "kiwi", "lemon"};

    std::srand(std::time(0)); // Seed for randomness

    // Fill the vector with random words, ensuring some repeat
    for (int i = 0; i < 100; ++i)
    {
        std::string word = possibleWords[std::rand() % possibleWords.size()];
        words.push_back(word);
    }

    std::map<std::string, int> wordCount;
    for (auto &word : words)
    {
        wordCount[word]++;
    }

    print(wordCount);

    int lielBiezums = wordCount.begin()->second;
    int mazBiezums = wordCount.begin()->second;
    for (auto it = wordCount.begin(); it != wordCount.end(); ++it)
    {
        if (it->second > lielBiezums)
            lielBiezums = it->second;
        if (it->second < mazBiezums)
            mazBiezums = it->second;
    }

    for (auto it = wordCount.begin(); it != wordCount.end(); )
    {
        if (it->second == lielBiezums or  it->second == mazBiezums)
        {
            it = wordCount.erase(it);
        }
        else
        {
            ++it;
        }
    }

    print(wordCount);
}