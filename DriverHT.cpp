#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <vector>
#include "HashTableFunc.hpp"

using namespace std;
//Main function reads in positive and negative words as well as the input file from python and performs sentiment analysis on it.
int main(int argc, char* argv[])
{
	float total = 0;
	float subtotal = 0;
	if(argc != 4)
	{
		cout << "Not enough command line arguments (3)!" << endl;
		return -1;
	}
	
	//Declare Tables and temp
	HashTable posT(1000);
	HashTable negT(2000);
	string temp;

	ifstream inStream;
	inStream.open(argv[1]);

	//Import Pos Words
	while(!inStream.eof())
	{
		getline(inStream, temp, '\n');
		posT.insertPos(temp);
	}
	inStream.close();

	ifstream inStream2;
	inStream2.open(argv[2]);

	//Import Neg Words
	while (!inStream2.eof())
	{
		getline(inStream2, temp, '\n');
		negT.insertNeg(temp);
	}
	inStream2.close();

	//Import file Document
	ifstream inStream3;
	inStream3.open(argv[3]);

	int score = 0;
	vector<int> score_array;
	while(inStream3 >> temp)
	{
		total++;
		//Check if temp is positive or negative, then add score and add word to graph.
		if(posT.searchItem(temp) != nullptr)
		{
			score++;
			subtotal++;
			score_array.push_back(score);
		}
		else if(negT.searchItem(temp) != nullptr)
		{
			score--;
			subtotal++;
			score_array.push_back(score);
		}
	}
	for(int i = 0; i < score_array.size(); i++)
	{
		cout << score_array[i] << endl;;
	}
	cout << "Percentage of good words: " << 50*(score/subtotal+1) << "%" << endl;
	cout << "Final score is: " << score << endl;

	printResult(score,total);
	if(time_score_array.size() > 50)
		system("py GraphingTimeSeries.py");
	
	return 0;
}
// Copyright 2019 Brandon Finley
//     Licensed under the Apache License,
//     Version 2.0(the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at

//     http://www.apache.org/licenses/LICENSE-2.0

// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

// Using these databases for a computer science project regarding data strutures and sentiment analysis
// The class is at University of Colorado: Boulder and has class level 2270
