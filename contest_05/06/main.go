type Cat struct {
	alive bool
}

type Box struct {
	catInside *Cat
}

func (b *Box) open() *Cat {
	if b.catInside == nil {
		rand.Seed(time.Now().UnixNano())
		isCatAlive := rand.Intn(2) == 0

		b.catInside = &Cat{alive: isCatAlive}
	}

	return b.catInside
}

func (c *Cat) is_alive() bool {
	return c.alive
}
