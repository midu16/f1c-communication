package main

import (
	"f1c-communication/pkg/f1c"
	"log"
)

func main() {
	log.Println("Starting DU server...")
	if err := f1c.StartServer(":38473"); err != nil {
		log.Fatalf("Failed to start DU server: %v", err)
	}
}

