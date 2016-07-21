/*
 * respace.cpp

 *
 *  Created on: Jul 20, 2016
 *      Author: chen
 */



#include <unordered_set>
#include <iostream>
#include <string>

using namespace std;
struct parseResult
{
	string parsed;
	int invalid;
};


parseResult split(unordered_set<string> dictionary,string sentence, unsigned int start)
{
	parseResult result;
	result.parsed = "";
	result.invalid = 0;
	cout << "start="<< start <<endl;
	if (start > sentence.length())
		return result;
	unsigned int index = start;
	unsigned int bestInvalid = 0xffffffff;

	while (index < sentence.length())
	{
		string partial;
		int invalid=0;
		partial += sentence.at(index);
		if (dictionary.find(partial) == dictionary.end())
		{
			invalid++;
			cout << "invalid="<< invalid <<endl;
		}
		else
		{
			//found partial in dictionary
			invalid = 0;
		}

		if (invalid < bestInvalid) // only if this is true we should go on on this path
		{
			cout << "partial="<< partial <<endl;

			parseResult recurse_result;
			recurse_result = split(dictionary, sentence, start+1);
			if (recurse_result.invalid < bestInvalid)
			{
				bestInvalid = recurse_result.invalid ;
			}
		}
		index++;
	}
	return result;
}

void bestSplit(unordered_set<string> dictionary,string sentence)
{
	cout << "sentence.length()="<< sentence.length() <<endl;
	split(dictionary, sentence, 0);
}

void bestSplitTest()
{
	unordered_set<string> dictionary={"hello","world"};
	string sentence="helloworld";
	bestSplit(dictionary, sentence);
}
