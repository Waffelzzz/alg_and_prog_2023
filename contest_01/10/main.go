package main

import "fmt"

func main() {

	var (
		firstAnswer  string
		secondAnswer string
		thirdAnswer  string
	)

	fmt.Scanf("%s %s %s", &firstAnswer, &secondAnswer, &thirdAnswer)

	if firstAnswer == "Да" {
		if secondAnswer == "Да" {
			if thirdAnswer == "Да" {
				fmt.Printf("Утка")
			} else {
				fmt.Printf("Пингвин")
			}
		} else {
			if thirdAnswer == "Да" {
				fmt.Printf("Плезиозавры")
			} else {
				fmt.Printf("Дельфин")
			}
		}
	} else {
		if secondAnswer == "Да" {
			if thirdAnswer == "Да" {
				fmt.Printf("Страус")
			} else {
				fmt.Printf("Курица")
			}
		} else {
			if thirdAnswer == "Да" {
				fmt.Printf("Жираф")
			} else {
				fmt.Printf("Кот")
			}
		}
	}
}
