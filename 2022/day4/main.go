package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {

	calcPartOne()
	calcPartTwo()
}

func calcPartOne() {
	file, _ := os.Open("input.txt")
	defer file.Close()
	scanner := bufio.NewScanner(file)

	count := 0
	for scanner.Scan() {
		line := strings.Split(scanner.Text(), ",")
		pairOne := strings.Split(line[0], "-")
		pairTwo := strings.Split(line[1], "-")

		if toInt(pairOne[0]) >= toInt(pairTwo[0]) &&
			toInt(pairOne[1]) <= toInt(pairTwo[1]) {
			count++
		} else if toInt(pairTwo[0]) >= toInt(pairOne[0]) &&
			toInt(pairTwo[1]) <= toInt(pairOne[1]) {
			count++
		}
	}

	fmt.Println(count)
}

func calcPartTwo() {
	file, _ := os.Open("input.txt")
	defer file.Close()
	scanner := bufio.NewScanner(file)

	count := 0
	for scanner.Scan() {
		line := strings.Split(scanner.Text(), ",")
		pairOne := strings.Split(line[0], "-")
		pairTwo := strings.Split(line[1], "-")

		p1Start, p1End := toInt(pairOne[0]), toInt(pairOne[1])
		p2Start, p2End := toInt(pairTwo[0]), toInt(pairTwo[1])

		if p1End >= p2Start && p2End >= p1Start {
			count++
		}
	}

	fmt.Println(count)
}

func toInt(num string) int {
	n, _ := strconv.Atoi(num)
	return n
}
