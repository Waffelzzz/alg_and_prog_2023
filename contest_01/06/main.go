package main

import "fmt"

func main() {

	var n int
	var numbers [5]int = [5]int{5000, 1000, 500, 200, 100}
	var count1 int = 0
	var count2 int = 0
	var count3 int = 0
	var count4 int = 0
	var count5 int = 0

	fmt.Scanf("%d", &n)

	for i := 0; i < 5; i++ {
		if i == 0 {
			count1 = n / numbers[i]
			n = n % numbers[i]
		}
		if i == 1 {
			count2 = n / numbers[i]
			n = n % numbers[i]
		}
		if i == 2 {
			count3 = n / numbers[i]
			n = n % numbers[i]
		}
		if i == 3 {
			count4 = n / numbers[i]
			n = n % numbers[i]
		}
		if i == 4 {
			count5 = n / numbers[i]
			n = n % numbers[i]
		}

	}
	fmt.Printf("%d %d %d %d %d", count1, count2, count3, count4, count5)

}
