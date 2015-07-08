package quiz

import "github.com/satori/go.uuid"

// Quiz models process of learning words from predefined set of cards.
// When the answer is correct, card is promoted to next compartment (see Box)
// When the answer is incorrect, card is demoted to first compartment
type Quiz struct {
	id               uuid.UUID
	originatingBoxID uuid.UUID
	cards            []uuid.UUID
}
