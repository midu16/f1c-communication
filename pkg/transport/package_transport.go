package transport

import (
	"fmt"
	"sync"
	"time"
)

// Package represents a simple data package.
type Package struct {
	ID      int
	Payload string
}

// Server simulates a server that sends packages.
type Server struct {
	sentPackages int
	mu           sync.Mutex
}

// Client simulates a client that receives packages.
type Client struct {
	receivedPackages int
	mu               sync.Mutex
}

// SendPackage sends a package from the server to the client.
func (s *Server) SendPackage(pkg Package, client *Client) {
	s.mu.Lock()
	s.sentPackages++
	s.mu.Unlock()

	// Simulate network delay
	time.Sleep(100 * time.Millisecond)

	// Simulate successful delivery
	client.ReceivePackage(pkg)
}

// ReceivePackage increments the count of successfully received packages on the client side.
func (c *Client) ReceivePackage(pkg Package) {
	c.mu.Lock()
	defer c.mu.Unlock()
	c.receivedPackages++
	fmt.Printf("Client: Successfully received package ID %d with payload: %s\n", pkg.ID, pkg.Payload)
}

// DisplayStats prints the statistics of packages sent and received.
func DisplayStats(server *Server, client *Client) {
	fmt.Printf("Server: Total packages sent: %d\n", server.sentPackages)
	fmt.Printf("Client: Total packages successfully received: %d\n", client.receivedPackages)
}

// Example usage
func main() {
	server := &Server{}
	client := &Client{}

	// Simulate sending packages
	for i := 1; i <= 10; i++ {
		pkg := Package{ID: i, Payload: fmt.Sprintf("Payload %d", i)}
		go server.SendPackage(pkg, client)
	}

	// Wait for all packages to be processed
	time.Sleep(2 * time.Second)

	// Display stats
	DisplayStats(server, client)
}
