package events

import "github.com/chuckpreslar/emission"

// EventType represents different event types, what else?
type EventType int

const (
	CardCorrect EventType = iota
	CardIncorrect
)

var Emitter = emission.NewEmitter()
