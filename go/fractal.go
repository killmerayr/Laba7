package main

import (
	"github.com/fogleman/gg"
)

func drawCantor(dc *gg.Context, x, y, length float64, depth int) {
	if depth == 0 || length < 2 {
		return
	}

	// Draw the line
	dc.DrawLine(x, y, x+length, y)
	dc.SetRGB(0, 0, 0)
	dc.Stroke()

	newY := y + 20

	// Left segment
	drawCantor(dc, x, newY, length/3, depth-1)
	// Right segment
	drawCantor(dc, x+2*length/3, newY, length/3, depth-1)
}

func main() {
	const width = 800
	const height = 600

	dc := gg.NewContext(width, height)
	dc.SetRGB(1, 1, 1)
	dc.Clear()

	drawCantor(dc, 50, 50, 700, 6)

	dc.SavePNG("cantor.png")
}
