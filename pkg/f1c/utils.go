package f1c

import (
	"log"
	"strconv"
	"strings"
)

// parsePort extracts the port from an address string (e.g., "192.168.1.20:38473").
func parsePort(address string) int {
	parts := strings.Split(address, ":")
	if len(parts) != 2 {
		log.Fatalf("Invalid address format: %s", address)
	}
	port, err := strconv.Atoi(parts[1])
	if err != nil || port <= 0 || port > 65535 {
		log.Fatalf("Invalid port in address: %s", address)
	}
	return port
}
