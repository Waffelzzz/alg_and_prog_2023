package main

import "fmt"

func main() {
	var (
		n   int
		res []int
		num float64
		a   int
	)

	fmt.Scan(&n)

	for i := 0; i < n; i++ {
		fmt.Scan(&a)
		res = append(res, a)
	}

	fmt.Print(res[0])

	for i := 1; i < (n - 1); i++ {
		num = (float64(res[i-1]) + float64(res[i]) + float64(res[i+1])) / 3
		fmt.Printf(" %f", num)
	}

	fmt.Print(" ")
	fmt.Print(res[n-1])

}
