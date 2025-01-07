package f1ap

import (
	"fmt"
	"log"
	"net"

	"github.com/ishidawataru/sctp"
)

// StartServer listens on a given address and handles incoming SCTP connections
func StartServer(address string) error {
	// Listen for SCTP connections
	listener, err := sctp.ListenSCTP("sctp", &sctp.SCTPAddr{
		IPAddrs: []net.IPAddr{{IP: net.ParseIP("0.0.0.0")}},
		Port:    38473,
	})
	if err != nil {
		return fmt.Errorf("failed to start SCTP server: %v", err)
	}
	defer listener.Close()

	log.Printf("SCTP server listening on %s\n", address)

	for {
		// Accept an incoming connection
		conn, err := listener.Accept()
		if err != nil {
			log.Printf("Failed to accept connection: %v", err)
			continue
		}

		// Handle the connection
		go handleConnection(conn.(*sctp.SCTPConn))
	}
}

// Modify the handleConnection function to cast TransactionID
func handleConnection(conn *sctp.SCTPConn) {
	defer conn.Close()

	buf := make([]byte, 2048)
	for {
		n, err := conn.Read(buf)
		if err != nil {
			if err.Error() == "EOF" {
				log.Printf("Client disconnected: %v", conn.RemoteAddr())
			} else {
				log.Printf("Error reading from connection: %v", err)
			}
			break
		}

		log.Printf("Received raw data: %x", buf[:n])

		var request F1SetupRequest
		if err := DecodeASN1(buf[:n], &request); err != nil {
			log.Printf("Error decoding F1SetupRequest: %v", err)
			break
		}

		log.Printf("F1SetupRequest: %+v", request)

		// Cast TransactionID to int before passing to NewF1SetupResponse
		response := NewF1SetupResponse(int(request.TransactionID), "Success")

		encodedResponse, err := EncodeF1SetupResponse(response)
		if err != nil {
			log.Printf("Error encoding F1SetupResponse: %v", err)
			break
		}

		if _, err := conn.Write(encodedResponse); err != nil {
			log.Printf("Error sending response: %v", err)
			break
		}
	}
}

// StartClient connects to the SCTP server at the provided address
func StartClient(serverAddress string) error {
	// Parse the server address and port
	host, port, err := net.SplitHostPort(serverAddress)
	if err != nil {
		return fmt.Errorf("invalid server address format: %v", err)
	}

	// Convert the host to an IP address
	serverIP := net.ParseIP(host)
	if serverIP == nil {
		return fmt.Errorf("invalid IP address: %s", host)
	}

	// Parse the port number
	serverPort, err := parsePort(port)
	if err != nil {
		return fmt.Errorf("invalid port number: %v", err)
	}

	// Create the SCTP connection
	conn, err := sctp.DialSCTP("sctp", nil, &sctp.SCTPAddr{
		IPAddrs: []net.IPAddr{{IP: serverIP}},
		Port:    serverPort,
	})
	if err != nil {
		return fmt.Errorf("failed to connect to SCTP server: %v", err)
	}
	defer conn.Close()

	log.Printf("Connected to SCTP server at %s\n", serverAddress)

	// Send a message to the server
	message := []byte("Hello from CU!")
	_, err = conn.Write(message)
	if err != nil {
		return fmt.Errorf("failed to send message: %v", err)
	}

	// Receive the server's response
	buf := make([]byte, 1024)
	n, err := conn.Read(buf)
	if err != nil {
		return fmt.Errorf("failed to read response: %v", err)
	}

	log.Printf("Received: %s", string(buf[:n]))
	return nil
}

// Helper function to parse a port number
func parsePort(port string) (int, error) {
	var p int
	_, err := fmt.Sscanf(port, "%d", &p)
	if err != nil || p < 1 || p > 65535 {
		return 0, fmt.Errorf("invalid port: %s", port)
	}
	return p, nil
}
