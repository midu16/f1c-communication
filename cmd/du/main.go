package main

import (
	"f1c-communication/pkg/f1ap"
	"log"
)

func main() {
	log.Println("Starting SCTP server on port :38473...")
	if err := f1ap.StartServer(":38473"); err != nil {
		log.Fatalf("Failed to start server: %v", err)
	}
}
