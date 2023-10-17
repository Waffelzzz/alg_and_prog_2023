package main

import "fmt"

func main() {
	var (
		first  int
		second float64
	)
	fmt.Scan(&first)
	fmt.Scan(&second)

	input := make(map[float64]int)
	for i := 0; i < first; i++ {
		var num float64
		fmt.Scan(&num)
		input[num] = 1
	}

	var prom int
	for j := range input {
		res := second - j
		if input[res] == 1 {
			if res >= j {
				fmt.Print(j, res)
				prom = 0
				break
			} else {
				fmt.Print(res, j)
				prom = 0
				break
			}
		} else {
			prom++
		}
	}

	if prom != 0 {
		fmt.Print("0 0")
	}
}
