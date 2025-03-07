
#include <vector>
using namespace std;

class Solution {

public:
    vector<int> findMissingAndRepeatedValues(const vector<vector<int>>& matrix) const {
        int rows = matrix.size();
        int columns = matrix[0].size();
        int numberOfElements = rows * columns;

        int repeatedValue = 0;
        int sumValuesInMatrix = 0;
        vector<bool> visited(numberOfElements + 1);

        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < columns; ++c) {
                int value = matrix[r][c];
                if (visited[value]) {
                    repeatedValue = value;
                }
                sumValuesInMatrix += value;
                visited[value] = true;
            }
        }

        int sumValuesInRange = (numberOfElements + 1) * numberOfElements / 2;
        int missingValue = sumValuesInRange - sumValuesInMatrix + repeatedValue;

        return vector<int>{repeatedValue, missingValue};
    }
};
