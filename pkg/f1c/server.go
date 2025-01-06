package f1c

import (
	"bufio"
	"encoding/json"
	"fmt"
	"net"
)

// StartServer initializes the DU server and listens for incoming connections.
func StartServer(address string) error {
	listener, err := net.Listen("tcp", address)
	if err != nil {
		return fmt.Errorf("failed to start server: %w", err)
	}
	defer listener.Close()

	fmt.Printf("DU Server listening on %s\n", address)

	for {
		conn, err := listener.Accept()
		if err != nil {
			fmt.Printf("Error accepting connection: %v\n", err)
			continue
		}
		go handleConnection(conn)
	}
}

func handleConnection(conn net.Conn) {
	defer conn.Close()
	fmt.Printf("Client connected: %s\n", conn.RemoteAddr())

	reader := bufio.NewReader(conn)
	for {
		// Read the incoming message
		message, err := reader.ReadString('\n')
		if err != nil {
			fmt.Printf("Connection closed by client: %v\n", err)
			return
		}

		// Decode the F1-C message
		var f1cMessage F1CMessage
		if err := json.Unmarshal([]byte(message), &f1cMessage); err != nil {
			fmt.Printf("Error decoding message: %v\n", err)
			continue
		}
		fmt.Printf("Received message: %+v\n", f1cMessage)

		// Respond to the client
		response := F1CMessage{
			MessageType: "Response",
			Payload:     "Acknowledged: " + f1cMessage.Payload,
		}
		responseBytes, _ := json.Marshal(response)
		conn.Write(append(responseBytes, '\n'))
	}
}
