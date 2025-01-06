package main

import (
	"f1c-communication/pkg/f1c"
	"log"
)

func main() {
	log.Println("Starting CU client...")
	if err := f1c.StartClient("localhost:38473"); err != nil {
		log.Fatalf("Failed to start CU client: %v", err)
	}
}
