package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	calcPartOne()
	calcPartTwo()
}

func calcPartOne() {
	file, _ := os.Open("input.txt")
	defer file.Close()
	scanner := bufio.NewScanner(file)

	sum := 0
	for scanner.Scan() {
		line := scanner.Text()
		firstHalf := line[:len(line)/2]
		secondHalf := line[len(line)/2:]

		common := getCommonCharacters([]string{firstHalf, secondHalf})
		for _, ch := range common {
			if ch >= 'a' && ch <= 'z' {
				sum += int(ch - 'a' + 1)
			}
			if ch >= 'A' && ch <= 'Z' {
				sum += int(ch - 'A' + 27)
			}
		}
	}

	fmt.Println(sum)
}

func calcPartTwo() {
	file, _ := os.Open("input.txt")
	defer file.Close()
	scanner := bufio.NewScanner(file)

	sum := 0
	groupCount := 0
	group := [3]string{}

	for scanner.Scan() {
		line := scanner.Text()

		group[groupCount] = line
		groupCount += 1
		if groupCount < 3 {
			continue
		}

		groupCount = 0
		common := getCommonCharacters(group[:])
		for _, ch := range common {
			if ch >= 'a' && ch <= 'z' {
				sum += int(ch - 'a' + 1)
			}
			if ch >= 'A' && ch <= 'Z' {
				sum += int(ch - 'A' + 27)
			}
		}
	}

	fmt.Println(sum)
}

func getCommonCharacters(strings []string) []rune {
	common := make(map[rune]struct{})

	for _, ch := range strings[0] {
		common[ch] = struct{}{}
	}

	for i := 1; i < len(strings); i++ {
		currentSet := make(map[rune]struct{})
		for _, ch := range strings[i] {
			currentSet[ch] = struct{}{}
		}

		for ch := range common {
			if _, exists := currentSet[ch]; !exists {
				delete(common, ch)
			}
		}
	}

	var result []rune
	for ch := range common {
		result = append(result, ch)
	}
	return result
}
