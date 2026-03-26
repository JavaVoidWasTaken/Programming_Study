#include <iostream>
using namespace std;

int main(){
	int size;
	cout << "Please enter the desired input size:\n> ";
	cin >> size;

	int* list = (int*) malloc (sizeof(int)*size);

	for (int i = 0; i < size; ++i){
		cin >> *(list+i);
	}

	for (int i = 0; i < size; ++i){
		cout << *(list+i) << endl;
	}


	
	return 0;
}

