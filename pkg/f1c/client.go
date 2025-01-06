package f1c

import (
	"bufio"
	"encoding/json"
	"fmt"
	"net"
)

// StartClient initializes the CU client and communicates with the DU server.
func StartClient(serverAddress string) error {
	conn, err := net.Dial("tcp", serverAddress)
	if err != nil {
		return fmt.Errorf("failed to connect to server: %w", err)
	}
	defer conn.Close()

	fmt.Printf("Connected to DU server at %s\n", serverAddress)

	reader := bufio.NewReader(conn)

	// Simulate sending 5 messages to the server
	for i := 1; i <= 5; i++ {
		// Create an F1-C message
		message := F1CMessage{
			MessageType: "Request",
			Payload:     fmt.Sprintf("Hello DU %d", i),
		}
		messageBytes, err := json.Marshal(message)
		if err != nil {
			return fmt.Errorf("failed to encode message: %w", err)
		}

		// Send the message to the server
		if _, err := conn.Write(append(messageBytes, '\n')); err != nil {
			return fmt.Errorf("failed to send message: %w", err)
		}

		// Read the server's response
		response, err := reader.ReadString('\n')
		if err != nil {
			return fmt.Errorf("failed to read response: %w", err)
		}

		var f1cResponse F1CMessage
		if err := json.Unmarshal([]byte(response), &f1cResponse); err != nil {
			fmt.Printf("Error decoding response: %v\n", err)
			continue
		}

		fmt.Printf("Received response: %+v\n", f1cResponse)
	}

	return nil
}
