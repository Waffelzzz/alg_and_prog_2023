func shift(data []int, steps int) {
	length := len(data)

	if steps > 0 {
		steps %= length
		data2 := make([]int, length)
		for i := 0; i < length; i++ {
			newIndex := (i + steps) % length
			data2[newIndex] = data[i]
		}
		copy(data, data2)
	}

	if steps < 0 {
		steps = (-steps) % length
		data2 := make([]int, length)
		for i := 0; i < length; i++ {
			newIndex := (i - steps + length) % length
			data2[newIndex] = data[i]
		}
		copy(data, data2)
	}
}
