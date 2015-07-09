package main

import (
	"fmt"

	"github.com/xwizard/karteczki/events"
	"github.com/xwizard/karteczki/quiz"
)

func main() {

	hello := func(to string) {
		fmt.Printf("Hello %s!\n", to)
	}

	count := func(count int) {
		for i := 0; i < count; i++ {
			fmt.Println(i)
		}
	}

	var quiz quiz.Quiz
	fmt.Println(quiz)
	events.Emitter.On(events.CardCorrect, hello).
		On(events.CardIncorrect, count).
		Emit(events.CardCorrect, "world").
		Emit(events.CardIncorrect, 5)
}
