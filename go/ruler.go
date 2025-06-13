package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Символы для разных уровней делений
func tickChar(level, maxLevel int) rune {
	if level == maxLevel {
		return '|'
	}
	if level >= maxLevel-1 {
		return ':'
	}
	return '.'
}

// Рекурсивная функция разметки линейки и сбор позиций для подписей
func drawTicks(ruler []rune, labels *[]int, left, right, level, maxLevel int) {
	if level == 0 {
		return
	}
	mid := (left + right) / 2
	ruler[mid] = tickChar(level, maxLevel)
	if level >= maxLevel-1 {
		*labels = append(*labels, mid)
	}
	drawTicks(ruler, labels, left, mid, level-1, maxLevel)
	drawTicks(ruler, labels, mid, right, level-1, maxLevel)
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	fmt.Print("Введите степень двойки (количество разбиений): ")
	input, _ := reader.ReadString('\n')
	input = strings.TrimSpace(input)
	n, _ := strconv.Atoi(input)

	length := (1 << n) + 1
	ruler := make([]rune, length)
	for i := range ruler {
		ruler[i] = ' '
	}
	labels := []int{}

	ruler[0] = '|'
	ruler[length-1] = '|'
	labels = append(labels, 0, length-1)

	drawTicks(ruler, &labels, 0, length-1, n, n)

	// Вывод линейки
	for _, c := range ruler {
		fmt.Printf("%c", c)
	}
	fmt.Println()

	// Подписи
	lastPos := 0
	for i := 0; i < length; i++ {
		found := false
		for _, pos := range labels {
			if pos == i {
				fmt.Print(i)
				lastPos = i
				found = true
				break
			}
		}
		if !found && i > lastPos {
			fmt.Print(" ")
		}
	}
	fmt.Println()
}
