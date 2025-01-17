package transport

import (
	"sync"
	"testing"
)

func TestServerClientPackageCommunication(t *testing.T) {
	server := &Server{}
	client := &Client{}

	const totalPackages = 10
	var wg sync.WaitGroup

	// Simulate sending packages
	for i := 1; i <= totalPackages; i++ {
		wg.Add(1)
		go func(pkgID int) {
			defer wg.Done()
			pkg := Package{ID: pkgID, Payload: "Payload " + string(rune(pkgID))}
			server.SendPackage(pkg, client)
		}(i)
	}

	// Wait for all goroutines to complete
	wg.Wait()

	// Display stats
	DisplayStats(server, client)

	// Validate results
	if server.sentPackages != totalPackages {
		t.Errorf("Expected %d packages sent, but got %d", totalPackages, server.sentPackages)
	}

	if client.receivedPackages != totalPackages {
		t.Errorf("Expected %d packages received, but got %d", totalPackages, client.receivedPackages)
	}
}
