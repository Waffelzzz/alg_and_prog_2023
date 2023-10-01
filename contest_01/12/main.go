package main

import "fmt"

func main() {
	var (
		count int
		X     int
	)

	fmt.Scanf("%d", &X)

	for X != 1 {
		if X%2 == 0 {
			X /= 2
		} else {
			X = 3*X + 1
		}
		count++
	}

	fmt.Printf("%d", count)
}
