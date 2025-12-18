#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
using namespace std;
using ll = long long;



int main(){
	int listSize, temp, prev, result = 0;
	vector<int> list;

	cin >> listSize;
	for (int i = 0; i < listSize; ++i){
		cin >> temp;
		list.push_back(temp);
	}

	sort(list.begin(), list.end());
	prev = list[0];
	
	for (int i = 0; i < list.size(); ++i){
		if (prev != list[i+1]){
			prev = list[i+1];
			++result;
		}
	}

	cout << result << endl;

	return 0;
}
