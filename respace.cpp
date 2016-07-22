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

static int recursions=0;
parseResult split(unordered_set<string> dictionary,string sentence, unsigned int start, parseResult memo[])
{
	parseResult result;
	result.parsed = "";
	result.invalid = 0;
	if (start >= sentence.length())
		return result;


	if (!(memo[start].parsed == ""))
		return memo[start];
	unsigned int index = start;
	unsigned int bestInvalid = 0xffffffff;
	string bestParsing;
	string partial;
	recursions++;
	while (index < sentence.length())
	{
		unsigned int invalid=0;
		partial += sentence.at(index);
		if (dictionary.find(partial) == dictionary.end())
		{
			invalid = partial.length();
//			cout << "invalid="<< invalid << " start="<< start <<endl;
		}
		else
		{
			//found partial in dictionary
			invalid = 0;
		}
		cout << "start="<< start << " len="<<sentence.length() << " partial="<< partial  << " invalid=" << invalid<<endl;

		if (invalid < bestInvalid) // only if this is true we should go on on this path
		{

			parseResult recurse_result;
			recurse_result = split(dictionary, sentence, index+1, memo);

			if ((invalid + recurse_result.invalid) < bestInvalid)
			{
				bestInvalid = invalid + recurse_result.invalid ;
				bestParsing = partial + " " + recurse_result.parsed;
				cout <<"start="<< (index+1) << " bestInvalid="<< bestInvalid << " bestParsed="<< bestParsing <<endl;
				if(bestInvalid == 0) break;
			}
		}
		index++;
	}//while (index < sentence.length()
	memo[start].parsed = bestParsing;
	memo[start].invalid = bestInvalid;
	return memo[start];
}

void bestSplit(unordered_set<string> dictionary,string sentence)
{
	parseResult res;
	parseResult * memo = new parseResult[sentence.length()];
	for (unsigned int i=0; i< sentence.length(); i++)
	{
		memo[i].parsed = "";
		cout << "memo[i].parsed ="<< memo[i].parsed  <<endl;
	}
	cout << "sentence.length()="<< sentence.length() <<endl;
	res = split(dictionary, sentence, 0, memo);
	cout << "recursions="<<recursions<<" result invalid="<< res.invalid <<endl << "result parsed="<< res.parsed <<endl;
}

void bestSplitTest()
{
	unordered_set<string> dictionary={"hello","world","strange","he","hell","range"};

	string sentence="hellostrangeworld";
	bestSplit(dictionary, sentence);
}
