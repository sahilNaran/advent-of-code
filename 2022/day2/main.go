package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	calcPartOne()
	calcPartTwo()
}

// A
// B
// C
// X - 1
// Y - 2
// Z - 3
func calcPartOne() {
	file, _ := os.Open("input.txt")
	defer file.Close()
	scanner := bufio.NewScanner(file)

	score := 0
	for scanner.Scan() {
		line := strings.Split(scanner.Text(), " ")
		if line[1] == "X" {
			score += 1
			if line[0] == "A" {
				score += 3
			}
			if line[0] == "C" {
				score += 6
			}
		}
		if line[1] == "Y" {
			score += 2
			if line[0] == "B" {
				score += 3
			}
			if line[0] == "A" {
				score += 6
			}
		}
		if line[1] == "Z" {
			score += 3
			if line[0] == "C" {
				score += 3
			}
			if line[0] == "B" {
				score += 6
			}
		}

	}
	fmt.Println(score)
}

func calcPartTwo() {
	file, _ := os.Open("input.txt")
	defer file.Close()
	scanner := bufio.NewScanner(file)
	var scoreMap = map[string]int{"A": 1, "B": 2, "C": 3}
	score := 0
	for scanner.Scan() {
		line := strings.Split(scanner.Text(), " ")
		neededResult := line[1]

		enemyPick := line[0]
		if neededResult == "Y" {
			score += 3
			score += getScoreForRPS(scoreMap, enemyPick)
		}
		if neededResult == "X" {
			if enemyPick == "A" {
				score += getScoreForRPS(scoreMap, "C")
			}
			if enemyPick == "B" {
				score += getScoreForRPS(scoreMap, "A")
			}
			if enemyPick == "C" {
				score += getScoreForRPS(scoreMap, "B")
			}
		}
		if neededResult == "Z" {
			score += 6
			if enemyPick == "A" {
				score += getScoreForRPS(scoreMap, "B")
			}
			if enemyPick == "B" {
				score += getScoreForRPS(scoreMap, "C")
			}
			if enemyPick == "C" {
				score += getScoreForRPS(scoreMap, "A")
			}
		}

	}
	fmt.Println(score)
}

func getScoreForRPS(scoringMap map[string]int, input string) int {
	return scoringMap[input]
}
