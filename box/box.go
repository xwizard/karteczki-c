package box

import "github.com/satori/go.uuid"

const compartmentAmount = 5

// Box is a container for cards.
// Cards are stored in compartments, each compartment has bigger capacity.
// When a compartment is full, Quiz can be created with cards from inside
type Box struct {
	id           uuid.UUID
	compartments [][]uuid.UUID
}

// NewBox returns new Box instance with randomly generated id
func NewBox() Box {
	return newBox(uuid.NewV4())
}

func newBox(id uuid.UUID) Box {
	return Box{id: id}
}

// PromoteCard moves card to next compartment and emits cardPromoted event.
func (box Box) PromoteCard(cardID uuid.UUID) {
}
