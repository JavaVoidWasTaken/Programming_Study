#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
using namespace std;
using ll = long long;

int main(){
	ll testCaseSize;
	string inputString;
	vector<int> empty(26, 0);
	vector<int> result(26, 0);
	vector<int> characterMap(26, 0);
	vector<vector<int>> sideOneCharacterMap, sideTwoCharacterMap;
	cin >> testCaseSize;

	// Fills char maps with an empty 26 long 0 list.
	for (int i = 0; i < testCaseSize; ++i)
	{
		sideOneCharacterMap.push_back(empty);
		sideTwoCharacterMap.push_back(empty);
	}

	// Actual algorithm.
	for (int i = 0; i < testCaseSize; ++i)
	{
		cin >> inputString;
		for (int o = 0; o < inputString.size(); ++o)
		{
			sideOneCharacterMap[i][inputString[o]-'a'] = sideOneCharacterMap[i][inputString[o]-'a']+1;
		}
		cin >> inputString;
		for (int o = 0; o < inputString.size(); ++o)
		{
			sideTwoCharacterMap[i][inputString[o]-'a'] = sideTwoCharacterMap[i][inputString[o]-'a']+1;
		}
	}

	// Result counting.
	for (int i = 0; i < 26; ++i)
	{	
		for (int o = 0; o < testCaseSize; ++o)
		{
			result[i] = result[i] + max(sideOneCharacterMap[o][i], sideTwoCharacterMap[o][i]);
		}
	}
	
	for (int i = 0; i < 26; ++i)
	{
		cout << result[i] << '\n';
	}


}