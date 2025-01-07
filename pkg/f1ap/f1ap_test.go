package f1ap

import (
	"testing"
)

func TestEncodeDecodeF1SetupRequest(t *testing.T) {
	req := F1SetupRequest{
		TransactionID: 1234,
		GlobalCUId:    "TestCU",
	}

	encoded, err := EncodeF1SetupRequest(req)
	if err != nil {
		t.Fatalf("Failed to encode F1SetupRequest: %v", err)
	}

	var decoded F1SetupRequest
	err = DecodeF1SetupRequest(encoded, &decoded)
	if err != nil {
		t.Fatalf("Failed to decode F1SetupRequest: %v", err)
	}

	if decoded.TransactionID != req.TransactionID || decoded.GlobalCUId != req.GlobalCUId {
		t.Errorf("Mismatch in decoded F1SetupRequest: got %+v, want %+v", decoded, req)
	}
}
