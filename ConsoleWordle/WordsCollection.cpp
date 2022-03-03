#include <iostream>
#include <fstream> //for reading the .txt
#include <string> //used for getline in while loop.
#include <vector>
#include "wordsCollection.h"

std::string getRandomWord() 
{	
	srand((unsigned int)time(NULL)); //cast to unsigned int since I got memory leak warnings.

	std::vector<std::string> words;	
	std::ifstream file("words.txt");
	std::string tempString;
	while (std::getline(file, tempString)) words.push_back(tempString);	
		
	std::string randomizedWord{};
	randomizedWord = words[rand() % words.size()];
		
	
	return randomizedWord;
}