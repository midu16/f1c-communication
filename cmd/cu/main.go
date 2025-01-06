package main

import (
	"f1c-communication/pkg/f1c"
	"flag"
	"log"
)

func main() {
	// Define a command-line flag for the server address
	serverAddress := flag.String("server", "localhost:38473", "F1-C server address (e.g., 192.168.1.100:38473)")
	flag.Parse()

	// Log the chosen server address
	log.Printf("Starting CU client, connecting to server at %s...\n", *serverAddress)

	// Start the client
	if err := f1c.StartClient(*serverAddress); err != nil {
		log.Fatalf("Failed to start CU client: %v", err)
	}
}
