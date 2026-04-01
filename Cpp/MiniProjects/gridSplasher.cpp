#include <iostream>
#include <vector>
using namespace std;

void print2DVector(vector<vector<char>> input2DVector, char widthSeparator, char heightSeparator){
	int height = input2DVector.size();
	int width = input2DVector[0].size();
	for (int x = 0; x < width; ++x){
		for (int y = 0; y < height; ++y){
			cout << input2DVector[x][y] << widthSeparator;
		}
		cout << heightSeparator;
	}
}

class splashGrid {
public:
	int gridWidth, gridHeight;
	vector<vector<char>> grid;
	
	// Creates a grid with the inputted width (x) and height (y).
	// Fills it with the emptyValue characters.
	splashGrid(int inputGridWidth, int inputGridHeight, char emptyValue) {
		gridWidth = inputGridWidth;
		gridHeight = inputGridHeight;
		vector<char> tempVect;

		for (int x = 0; x < gridWidth; ++x){
			tempVect.push_back(emptyValue);
		}
		for (int y = 0; y < gridHeight; ++y){
			grid.push_back(tempVect);
		}
	}
	
	// TODO: Optimize this algorithm.
	// Splashes the grid with a diamond shape centered on the x y coordinates. Replaces all affected tiles with pattern.
	// EXAMPLE: size=2, x=1, y=1, pattern='X'
	// - - -    - X -
	// - - - -> X X X
	// - - -    - X -
	void applySplash(int size, int centerX, int centerY, char pattern){
		// Difference in Y and X values compared to the center.
		int deltaY, deltaX;
		for (int x = 0; x < gridWidth; ++x){
			for (int y = 0; y < gridHeight; ++y){
				deltaX = abs(x-centerX);
				deltaY = abs(y-centerY);
				if (abs(deltaX+deltaY) < size){
					grid[x][y] = pattern;
				}
			}
		}
	}
};

int main(){
	int width = 10;
	int length = 10;
	char defaultValue = '-';

	splashGrid currentGrid(width, length, defaultValue);
	
	currentGrid.applySplash(2, 5, 5, 'X');	

	print2DVector(currentGrid.grid, ' ', '\n');
	cout << '\n';
}
