package f1c

import (
	"fmt"
	"log"
	"net"
	"strings"

	"github.com/ishidawataru/sctp"
)

// StartClient connects to the SCTP server at the given address
func StartClient(serverAddress string) error {
	serverIP := strings.Split(serverAddress, ":")[0]
	port := parsePort(serverAddress)

	conn, err := sctp.DialSCTP("sctp", nil, &sctp.SCTPAddr{
		IPAddrs: []net.IPAddr{{IP: net.ParseIP(serverIP)}},
		Port:    port,
	})
	if err != nil {
		return fmt.Errorf("failed to connect to server: %v", err)
	}
	defer conn.Close()

	log.Printf("Connected to server: %s", serverAddress)

	// Example communication: send a message and read response
	msg := []byte("Hello from CU!")
	_, err = conn.Write(msg)
	if err != nil {
		return fmt.Errorf("failed to send message: %v", err)
	}

	buf := make([]byte, 1024)
	n, err := conn.Read(buf)
	if err != nil {
		return fmt.Errorf("failed to read response: %v", err)
	}

	log.Printf("Received from server: %s", string(buf[:n]))
	return nil
}
