package main

import (
	"fmt"
	"sync"
)

type Singleton struct {
	name string
}

var (
	instance *Singleton
	once     sync.Once
)

func getInstance() *Singleton {
	once.Do(func() {
		instance = &Singleton{}
	})
	return instance
}

func main() {

	fmt.Printfln(getInstance().name)
}
