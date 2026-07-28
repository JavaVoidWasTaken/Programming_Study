#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void output(double item) {
    int front = item;
    if (front == item) {
        cout << item << ".0";
    } else {
        cout << front;
        front = item*10;
        front %= 10;
        cout << '.' << front;
    }
}

int main() {
    int size, temp;
    double result;
    vector<int> list;

    cin >> size;

    if (size == 1) {
        cin >> temp;
        output(temp);
        return 0;
    }

    for (int i = 0; i < size; ++i) {
        cin >> temp;
        list.push_back(temp);
    }

    sort(list.begin(), list.end());

    if (size%2 == 0) {
        result = double(list[(size/2)-1]+list[size/2])/2;
    } else {
        result = list[(size/2)];
    }

    output(result);
}


    
