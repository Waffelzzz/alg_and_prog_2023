func isLucky(num string) bool {
	var (
		count1 int
		count2 int
	)

	count1 = 0
	count2 = 0

	for i := 0; i < 3; i++ {
		count1 = count1 + int(num[i])
	}

	for j := 3; j < 6; j++ {
		count2 = count2 + int(num[j])
	}

	if count1 == count2 {
		return true
	}

	return false
}
