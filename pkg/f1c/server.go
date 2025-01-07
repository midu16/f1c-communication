package f1c

import (
	"fmt"
	"io"
	"log"
	"net"

	"github.com/ishidawataru/sctp"
)

func StartServer(port string) {
	addr := &sctp.SCTPAddr{
		IPAddrs: []net.IPAddr{{IP: net.ParseIP("0.0.0.0")}},
		Port:    parsePort(port),
	}

	listener, err := sctp.ListenSCTP("sctp", addr)
	if err != nil {
		log.Fatalf("Failed to start SCTP server: %v", err)
	}
	defer listener.Close()

	fmt.Printf("SCTP server listening on port %s\n", port)

	for {
		conn, err := listener.Accept()
		if err != nil {
			log.Printf("Failed to accept connection: %v", err)
			continue
		}

		go handleConnection(conn.(*sctp.SCTPConn))
	}
}

func handleConnection(conn *sctp.SCTPConn) {
	defer conn.Close()

	buf := make([]byte, 1024)
	for {
		n, err := conn.Read(buf)
		if err != nil {
			// Handle EOF gracefully
			if err == io.EOF {
				log.Printf("Connection closed by client")
				break
			}

			log.Printf("Error reading from connection: %v", err)
			break
		}

		fmt.Printf("Received: %s\n", string(buf[:n]))

		// Respond to the client
		_, err = conn.Write([]byte("Acknowledged"))
		if err != nil {
			log.Printf("Error writing to connection: %v", err)
			break
		}
	}
}
