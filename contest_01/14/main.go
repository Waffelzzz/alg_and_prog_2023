package main

import "fmt"

func main() {
	var row, col int

	fmt.Scan(&col)

	fmt.Scan(&row)

	fmt.Printf("    |")

	for i := 1; i <= row; i++ {
		if i < 10 {
			fmt.Printf("   %d", i)
		} else {
			fmt.Printf("  %d", i)
		}
	}

	fmt.Println()
	fmt.Printf("   --")
	for i := 1; i <= 4*row; i++ {
		fmt.Printf("-")
	}
	fmt.Println()

	for j := 1; j <= col; j++ {
		if j < 10 {
			fmt.Printf("   %d|", j)
		} else {
			fmt.Printf("  %d|", j)
		}
		for k := 1; k <= row; k++ {
			if k*j < 10 {
				fmt.Printf("   %d", k*j)
			} else if k*j < 100 {
				fmt.Printf("  %d", k*j)
			} else {
				fmt.Printf(" %d", k*j)
			}
		}
		fmt.Println()
	}
}
