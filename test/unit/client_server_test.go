package unit

import (
	"f1c-communication/pkg/transport"
	"testing"
)

func TestStartServer(t *testing.T) {
	err := transport.StartServer()
	if err != nil {
		t.Fatalf("Failed to start server: %v", err)
	}
}

func TestStartClient(t *testing.T) {
	err := transport.StartClient()
	if err != nil {
		t.Fatalf("Failed to start client: %v", err)
	}
}
