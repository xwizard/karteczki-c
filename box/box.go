package box

import "github.com/satori/go.uuid"

const COMPARTMEN_AMOUNT = 5

// Box is a container for cards.
// Cards are stored in compartments, each compartment has bigger capacity.
// When a compartment is full, Quiz can be created with cards from inside
type Box struct {
	id           uuid.UUID
	compartments [][]uuid.UUID
}
