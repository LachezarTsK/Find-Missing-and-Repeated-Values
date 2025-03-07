
package main

func findMissingAndRepeatedValues(matrix [][]int) []int {
    rows := len(matrix)
    columns := len(matrix[0])
    numberOfElements := rows * columns

    repeatedValue := 0
    sumValuesInMatrix := 0
    visited := make([]bool, numberOfElements+1)

    for r := range rows {
        for c := range columns {
            value := matrix[r][c]
            if visited[value] {
                repeatedValue = value
            }
            sumValuesInMatrix += value
            visited[value] = true
        }
    }

    sumValuesInRange := (numberOfElements + 1) * numberOfElements / 2
    missingValue := sumValuesInRange - sumValuesInMatrix + repeatedValue

    return []int{repeatedValue, missingValue}
}
