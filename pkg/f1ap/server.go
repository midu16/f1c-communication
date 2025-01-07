package f1ap

import "log"

func ExampleServerUsage() {
	err := StartServer(":38473")
	if err != nil {
		log.Fatalf("Error starting server: %v", err)
	}
}
