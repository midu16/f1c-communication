package f1ap

import (
	"testing"
)

func TestParsePort(t *testing.T) {
	port, err := parsePort("38473")
	if err != nil || port != 38473 {
		t.Errorf("parsePort failed: got %d, want 38473", port)
	}

	_, err = parsePort("invalid")
	if err == nil {
		t.Errorf("parsePort should fail for invalid input")
	}
}

func TestStartServer(t *testing.T) {
	go func() {
		err := StartServer(":38473")
		if err != nil {
			t.Errorf("Failed to start server: %v", err)
		}
	}()
	// Optionally, add SCTP connection mock or tests here.
}
