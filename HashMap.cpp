/*
 * hashmap.cpp
 *
 *  Created on: Jul 15, 2016
 *      Author: chen
 */


#include <string>
#include <sstream>
#include <iostream>
#include <map>
#include <unordered_map>
#include <algorithm>
using namespace std;
unordered_map<string,int> hashBookWordMap;

void setupHashMapForWordFrequency(string book)
{
	stringstream ssBook(book);
	string word;
	for (int i = 0; ssBook >> word; i++)
	{
		//erase by doing remove spaces comma and period
		word.erase(std::remove(word.begin(),word.end(),' '),word.end());
		word.erase(std::remove(word.begin(),word.end(),'.'),word.end());
		word.erase(std::remove(word.begin(),word.end(),','),word.end());

		//transform to lower case
		std::transform(word.begin(), word.end(), word.begin(), ::tolower);
		unordered_map<string,int>::iterator it;
		it = hashBookWordMap.find(word);
		if (it == hashBookWordMap.end())
		{
			//not found in hash
			hashBookWordMap.insert(make_pair(word,1));
			cout << word << " inserted" << endl;
		}
		else
		{
			//fount in hash, increment count
			(it->second)++;
			cout << it->first << " : " << it->second << endl;
		}
	}
}


void findWordInBook(string book, string word)
{
	unordered_map<string,int>::iterator it;
	setupHashMapForWordFrequency(book);
	it = hashBookWordMap.find(word);
	cout << it->second << endl;
}
