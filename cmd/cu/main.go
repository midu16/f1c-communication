package main

import (
	"f1c-communication/pkg/f1ap"
	"flag"
	"log"
)

func main() {
	serverAddress := flag.String("server", "127.0.0.1:38473", "SCTP server address")
	flag.Parse()

	log.Printf("Connecting to SCTP server at %s...\n", *serverAddress)
	if err := f1ap.StartClient(*serverAddress); err != nil {
		log.Fatalf("Failed to connect to server: %v", err)
	}
}
