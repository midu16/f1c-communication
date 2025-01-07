package f1ap

import "log"

func ExampleClientUsage() {
	err := StartClient("127.0.0.1")
	if err != nil {
		log.Fatalf("Error connecting to server: %v", err)
	}
}
