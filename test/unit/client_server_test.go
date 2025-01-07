package unit

import (
	"testing"
	"time"

	"f1c-communication/pkg/transport"
)

func TestClientServerInteraction(t *testing.T) {
	go func() {
		err := transport.StartServer(":38473")
		if err != nil {
			t.Fatalf("Server failed to start: %v", err)
		}
	}()

	// Allow server to start
	time.Sleep(1 * time.Second)

	err := transport.StartClient("127.0.0.1:38473")
	if err != nil {
		t.Fatalf("Client failed to connect: %v", err)
	}
}
