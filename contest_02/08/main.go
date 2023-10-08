import "strings"

func isPalindrome(s string) bool {
	s = strings.ToLower(s)

	i := 0
	j := len(s) - 1

	for i < j {
		for i < j && !isAlphanumeric(s[i]) {
			i++
		}

		for i < j && !isAlphanumeric(s[j]) {
			j--
		}

		if s[i] != s[j] {
			return false
		}

		i++
		j--
	}

	return true
}

func isAlphanumeric(c byte) bool {
	return (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9')
}
