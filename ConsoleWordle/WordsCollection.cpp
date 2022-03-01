#include <iostream>
#include <fstream> //for reading the .txt
#include <string> //used for getline in while loop.
#include <vector>
#include "WordsCollection.h"

std::string getRandomWord() //used for checking the list of words, randomize a word and return it.
{

	srand((unsigned int)time(NULL)); //had to cast to unsigned int since I got memory leak warnings. 

	std::string randomizedWord{};

	std::vector<std::string> words;
	std::ifstream file("words.txt");

	std::string line;
	while (std::getline(file, line)) words.push_back(line);

	randomizedWord = words[rand() % words.size()];
	
	return randomizedWord;
}