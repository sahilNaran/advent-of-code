package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {

	calcPartOne()
	calcPartTwo()
}

func calcPartOne() {
	file, _ := os.Open("input.txt")
	defer file.Close()
	scanner := bufio.NewScanner(file)
	current := 0
	max := 0
	for scanner.Scan() {
		line := scanner.Text()
		if len(line) != 0 {
			num, _ := strconv.Atoi(line)
			current += num
		} else {
			if current > max {
				max = current
			}
			current = 0
		}
	}
	fmt.Println(max)
}

func calcPartTwo() {
	file, _ := os.Open("input.txt")
	defer file.Close()

	scanner := bufio.NewScanner(file)

	current := 0
	maxes := [3]int{}

	for scanner.Scan() {
		line := scanner.Text()
		if len(line) != 0 {
			num, _ := strconv.Atoi(line)
			current += num
		} else {
			minIndex := 0
			for i := 1; i < 3; i++ {
				if maxes[i] < maxes[minIndex] {
					minIndex = i
				}
			}
			if current > maxes[minIndex] {
				maxes[minIndex] = current
			}
			current = 0
		}
	}
	sum := 0
	for i := ; i < 3; i++ {
		if maxes[i] > maxes[maxIndex] {
			maxIndex = i
		}
	}
  fmt
}
