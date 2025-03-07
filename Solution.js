
/**
 * @param {number[][]} matrix
 * @return {number[]}
 */
var findMissingAndRepeatedValues = function (matrix) {
    const rows = matrix.length;
    const columns = matrix[0].length;
    const numberOfElements = rows * columns;

    let repeatedValue = 0;
    let sumValuesInMatrix = 0;
    const visited = new Array(numberOfElements + 1).fill(false);

    for (let r = 0; r < rows; ++r) {
        for (let c = 0; c < columns; ++c) {
            const value = matrix[r][c];
            if (visited[value]) {
                repeatedValue = value;
            }
            sumValuesInMatrix += value;
            visited[value] = true;
        }
    }

    const sumValuesInRange = (numberOfElements + 1) * numberOfElements / 2;
    const missingValue = sumValuesInRange - sumValuesInMatrix + repeatedValue;

    return [repeatedValue, missingValue];
};
