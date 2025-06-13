package main

import (
	"bufio"
	"fmt"
	"os"
	"unicode"
)

type Calculator struct{}

func (c *Calculator) calculate(s string) int {
	index := 0
	return c.parse(s, &index)
}

func (c *Calculator) parse(s string, i *int) int {
	result := 0
	sign := 1
	num := 0

	for *i < len(s) {
		cChar := rune(s[*i])

		if unicode.IsDigit(cChar) {
			num = num*10 + int(cChar-'0')
		} else if cChar == '+' {
			result += sign * num
			num = 0
			sign = 1
		} else if cChar == '-' {
			result += sign * num
			num = 0
			sign = -1
		} else if cChar == '(' {
			*i++ // пропускаем (
			num = c.parse(s, i)
		} else if cChar == ')' {
			result += sign * num
			return result
		} else if cChar == ' ' {
			// просто пропускаем
		}
		*i++
	}

	result += sign * num
	return result
}

func main() {
	calc := &Calculator{}

	fmt.Print("Введите выражение: ")
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	expr := scanner.Text()

	result := calc.calculate(expr)
	fmt.Println("Результат:", result)
}
