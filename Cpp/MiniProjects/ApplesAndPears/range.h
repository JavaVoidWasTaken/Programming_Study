#pragma once

vector<int> range(int start, int end) {
	vector<int> result;
	for (int i = start; i < end; ++i) {
		result.push_back(i);
	}
	return result;
}

bool isInRange(int index, int end) {
	if (index < end && index >= 0) {
		return true;
	}
	return false;
}
