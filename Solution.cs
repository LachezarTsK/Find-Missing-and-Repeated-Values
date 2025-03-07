
using System;

public class Solution
{
    public int[] FindMissingAndRepeatedValues(int[][] matrix)
    {
        int rows = matrix.Length;
        int columns = matrix[0].Length;
        int numberOfElements = rows * columns;

        int repeatedValue = 0;
        int sumValuesInMatrix = 0;
        bool[] visited = new bool[numberOfElements + 1];

        for (int r = 0; r < rows; ++r)
        {
            for (int c = 0; c < columns; ++c)
            {
                int value = matrix[r][c];
                if (visited[value])
                {
                    repeatedValue = value;
                }
                sumValuesInMatrix += value;
                visited[value] = true;
            }
        }

        int sumValuesInRange = (numberOfElements + 1) * numberOfElements / 2;
        int missingValue = sumValuesInRange - sumValuesInMatrix + repeatedValue;

        return new int[] { repeatedValue, missingValue };
    }
}
