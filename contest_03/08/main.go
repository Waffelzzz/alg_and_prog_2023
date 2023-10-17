package main

import "fmt"

func main() {
	var num int
	fmt.Scanln(&num)

	counts := make(map[int]int)
	for i := 0; i < num; i++ {
		var num1 int
		fmt.Scan(&num1)
		counts[num1]++

		if counts[num1] == 2 {
			counts[num1] = 0
		}
	}

	for j := range counts {
		if counts[j] == 1 {
			fmt.Println(j)
			break
		}
	}
}

