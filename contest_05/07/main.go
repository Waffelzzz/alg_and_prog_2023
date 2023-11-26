type Water struct {
	temper int
}

type Teapot struct {
	temper1 int
}

func NewWater(temp int) Water {
	var water Water
	water.temper = temp
	return water
}

func NewTeapot(water1 Water) Teapot {
	var teapot Teapot
	teapot.temper1 = water1.temper
	return teapot
}

func (t *Teapot) is_boiling() bool {
	if t.temper1 >= 100 {
		return true
	}
	return false
}

func (t *Teapot) heat_up(heat int) int {
	t.temper1 += heat
	return t.temper1
}
