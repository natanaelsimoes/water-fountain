#include <iostream>
#include <vector>

using namespace std;

int maxWater(vector<int> blocks, int index) {
	int maxHeightLeft = -1, maxHeightRight = -1, length = blocks.size(), current = blocks[index];
	for (int i = 0; i < index; i++)
		if (blocks[i] > current && blocks[i] > maxHeightLeft)
			maxHeightLeft = blocks[i];
	for (int i = index + 1; i < length; i++)
		if (blocks[i] > current && blocks[i] > maxHeightRight)
			maxHeightRight = blocks[i];
	if (maxHeightLeft == -1 || maxHeightRight == -1) return 0;
	return maxHeightLeft < maxHeightRight ? maxHeightLeft - current : maxHeightRight - current;
}

int main()
{
	int cases, vectorLength, water;
	cin >> cases;
	while (cases > 0) {
		water = 0;
		cin >> vectorLength;
		vector<int> blocks(vectorLength);
		for (int i = 0; i < vectorLength; i++)
			cin >> blocks[i];
		for (int i = 0; i < vectorLength; i++)
			water += maxWater(blocks, i);
		cout << water << endl;
		cases--;
	}
}
