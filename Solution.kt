
class Solution {

    fun findMissingAndRepeatedValues(matrix: Array<IntArray>): IntArray {
        val rows = matrix.size
        val columns = matrix[0].size
        val numberOfElements = rows * columns

        var repeatedValue = 0
        var sumValuesInMatrix = 0
        val visited = BooleanArray(numberOfElements + 1)

        for (r in 0..<rows) {
            for (c in 0..<columns) {
                val value = matrix[r][c]
                if (visited[value]) {
                    repeatedValue = value
                }
                sumValuesInMatrix += value
                visited[value] = true
            }
        }

        val sumValuesInRange = (numberOfElements + 1) * numberOfElements / 2
        val missingValue = sumValuesInRange - sumValuesInMatrix + repeatedValue

        return intArrayOf(repeatedValue, missingValue)
    }
}
